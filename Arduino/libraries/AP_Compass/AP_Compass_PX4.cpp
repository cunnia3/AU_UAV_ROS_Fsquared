/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
/*
 *       AP_Compass_PX4.cpp - Arduino Library for PX4 magnetometer
 *
 *       This library is free software; you can redistribute it and / or
 *       modify it under the terms of the GNU Lesser General Public
 *       License as published by the Free Software Foundation; either
 *       version 2.1 of the License, or (at your option) any later version.
 */


#include <AP_HAL.h>

#if CONFIG_HAL_BOARD == HAL_BOARD_PX4
#include "AP_Compass_PX4.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <drivers/drv_mag.h>
#include <stdio.h>
#include <errno.h>

extern const AP_HAL::HAL& hal;

// Public Methods //////////////////////////////////////////////////////////////

bool AP_Compass_PX4::init(void)
{
	_mag_fd = open(MAG_DEVICE_PATH, O_RDONLY);
	if (_mag_fd < 0) {
        hal.console->printf("Unable to open " MAG_DEVICE_PATH);
        return false;
	}

	/* set the mag internal poll rate to at least 150Hz */
	ioctl(_mag_fd, MAGIOCSSAMPLERATE, 150);

	/* set the driver to poll at 150Hz */
	ioctl(_mag_fd, SENSORIOCSPOLLRATE, 150);

    // average over up to 10 samples
    ioctl(_mag_fd, SENSORIOCSQUEUEDEPTH, 10);

    healthy = false;
    _count = 0;
    _sum.zero();

    return true;
}

bool AP_Compass_PX4::read(void)
{
    accumulate();
    while (_count == 0) {
        accumulate();
        if (_count == 0) {
            hal.scheduler->delay(1);
        }
    }

    _sum /= _count;
    _sum *= 1000;
    _sum.rotate(_orientation);
    _sum.rotate(_board_orientation);
    _sum += _offset.get();

    mag_x = _sum.x;
    mag_y = _sum.y;
    mag_z = _sum.z;

    _sum.zero();
    _count = 0;

    last_update = _last_timestamp;

    return true;
}

void AP_Compass_PX4::accumulate(void)
{
    struct mag_report mag_report;
    while (::read(_mag_fd, &mag_report, sizeof(mag_report)) == sizeof(mag_report) &&
           mag_report.timestamp != _last_timestamp) {
        _sum += Vector3f(mag_report.x, mag_report.y, mag_report.z);
        _count++;
        _last_timestamp = mag_report.timestamp;
        healthy = true;
    }
}

#endif // CONFIG_HAL_BOARD
