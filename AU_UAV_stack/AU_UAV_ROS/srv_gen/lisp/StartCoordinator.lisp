; Auto-generated. Do not edit!


(cl:in-package AU_UAV_ROS-srv)


;//! \htmlinclude StartCoordinator-request.msg.html

(cl:defclass <StartCoordinator-request> (roslisp-msg-protocol:ros-message)
  ((indicator
    :reader indicator
    :initarg :indicator
    :type cl:string
    :initform ""))
)

(cl:defclass StartCoordinator-request (<StartCoordinator-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StartCoordinator-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StartCoordinator-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name AU_UAV_ROS-srv:<StartCoordinator-request> is deprecated: use AU_UAV_ROS-srv:StartCoordinator-request instead.")))

(cl:ensure-generic-function 'indicator-val :lambda-list '(m))
(cl:defmethod indicator-val ((m <StartCoordinator-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader AU_UAV_ROS-srv:indicator-val is deprecated.  Use AU_UAV_ROS-srv:indicator instead.")
  (indicator m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StartCoordinator-request>) ostream)
  "Serializes a message object of type '<StartCoordinator-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'indicator))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'indicator))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StartCoordinator-request>) istream)
  "Deserializes a message object of type '<StartCoordinator-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'indicator) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'indicator) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StartCoordinator-request>)))
  "Returns string type for a service object of type '<StartCoordinator-request>"
  "AU_UAV_ROS/StartCoordinatorRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartCoordinator-request)))
  "Returns string type for a service object of type 'StartCoordinator-request"
  "AU_UAV_ROS/StartCoordinatorRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StartCoordinator-request>)))
  "Returns md5sum for a message object of type '<StartCoordinator-request>"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StartCoordinator-request)))
  "Returns md5sum for a message object of type 'StartCoordinator-request"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StartCoordinator-request>)))
  "Returns full string definition for message of type '<StartCoordinator-request>"
  (cl:format cl:nil "string indicator~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StartCoordinator-request)))
  "Returns full string definition for message of type 'StartCoordinator-request"
  (cl:format cl:nil "string indicator~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StartCoordinator-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'indicator))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StartCoordinator-request>))
  "Converts a ROS message object to a list"
  (cl:list 'StartCoordinator-request
    (cl:cons ':indicator (indicator msg))
))
;//! \htmlinclude StartCoordinator-response.msg.html

(cl:defclass <StartCoordinator-response> (roslisp-msg-protocol:ros-message)
  ((error
    :reader error
    :initarg :error
    :type cl:string
    :initform ""))
)

(cl:defclass StartCoordinator-response (<StartCoordinator-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StartCoordinator-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StartCoordinator-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name AU_UAV_ROS-srv:<StartCoordinator-response> is deprecated: use AU_UAV_ROS-srv:StartCoordinator-response instead.")))

(cl:ensure-generic-function 'error-val :lambda-list '(m))
(cl:defmethod error-val ((m <StartCoordinator-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader AU_UAV_ROS-srv:error-val is deprecated.  Use AU_UAV_ROS-srv:error instead.")
  (error m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StartCoordinator-response>) ostream)
  "Serializes a message object of type '<StartCoordinator-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'error))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'error))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StartCoordinator-response>) istream)
  "Deserializes a message object of type '<StartCoordinator-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'error) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'error) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StartCoordinator-response>)))
  "Returns string type for a service object of type '<StartCoordinator-response>"
  "AU_UAV_ROS/StartCoordinatorResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartCoordinator-response)))
  "Returns string type for a service object of type 'StartCoordinator-response"
  "AU_UAV_ROS/StartCoordinatorResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StartCoordinator-response>)))
  "Returns md5sum for a message object of type '<StartCoordinator-response>"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StartCoordinator-response)))
  "Returns md5sum for a message object of type 'StartCoordinator-response"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StartCoordinator-response>)))
  "Returns full string definition for message of type '<StartCoordinator-response>"
  (cl:format cl:nil "string error~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StartCoordinator-response)))
  "Returns full string definition for message of type 'StartCoordinator-response"
  (cl:format cl:nil "string error~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StartCoordinator-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'error))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StartCoordinator-response>))
  "Converts a ROS message object to a list"
  (cl:list 'StartCoordinator-response
    (cl:cons ':error (error msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'StartCoordinator)))
  'StartCoordinator-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'StartCoordinator)))
  'StartCoordinator-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartCoordinator)))
  "Returns string type for a service object of type '<StartCoordinator>"
  "AU_UAV_ROS/StartCoordinator")