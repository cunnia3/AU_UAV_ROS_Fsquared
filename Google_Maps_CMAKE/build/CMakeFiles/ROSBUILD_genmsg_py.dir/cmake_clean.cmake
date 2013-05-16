FILE(REMOVE_RECURSE
  "../src/Google_Maps_CMAKE/msg"
  "../src/Google_Maps_CMAKE/srv"
  "../msg_gen"
  "../srv_gen"
  "../msg_gen"
  "../srv_gen"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/Google_Maps_CMAKE/msg/__init__.py"
  "../src/Google_Maps_CMAKE/msg/_TelemetryUpdate.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
