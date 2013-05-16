; Auto-generated. Do not edit!


(cl:in-package AU_UAV_ROS-srv)


;//! \htmlinclude StartCollisionAvoidance-request.msg.html

(cl:defclass <StartCollisionAvoidance-request> (roslisp-msg-protocol:ros-message)
  ((indicator
    :reader indicator
    :initarg :indicator
    :type cl:string
    :initform ""))
)

(cl:defclass StartCollisionAvoidance-request (<StartCollisionAvoidance-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StartCollisionAvoidance-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StartCollisionAvoidance-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name AU_UAV_ROS-srv:<StartCollisionAvoidance-request> is deprecated: use AU_UAV_ROS-srv:StartCollisionAvoidance-request instead.")))

(cl:ensure-generic-function 'indicator-val :lambda-list '(m))
(cl:defmethod indicator-val ((m <StartCollisionAvoidance-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader AU_UAV_ROS-srv:indicator-val is deprecated.  Use AU_UAV_ROS-srv:indicator instead.")
  (indicator m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StartCollisionAvoidance-request>) ostream)
  "Serializes a message object of type '<StartCollisionAvoidance-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'indicator))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'indicator))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StartCollisionAvoidance-request>) istream)
  "Deserializes a message object of type '<StartCollisionAvoidance-request>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StartCollisionAvoidance-request>)))
  "Returns string type for a service object of type '<StartCollisionAvoidance-request>"
  "AU_UAV_ROS/StartCollisionAvoidanceRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartCollisionAvoidance-request)))
  "Returns string type for a service object of type 'StartCollisionAvoidance-request"
  "AU_UAV_ROS/StartCollisionAvoidanceRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StartCollisionAvoidance-request>)))
  "Returns md5sum for a message object of type '<StartCollisionAvoidance-request>"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StartCollisionAvoidance-request)))
  "Returns md5sum for a message object of type 'StartCollisionAvoidance-request"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StartCollisionAvoidance-request>)))
  "Returns full string definition for message of type '<StartCollisionAvoidance-request>"
  (cl:format cl:nil "string indicator~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StartCollisionAvoidance-request)))
  "Returns full string definition for message of type 'StartCollisionAvoidance-request"
  (cl:format cl:nil "string indicator~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StartCollisionAvoidance-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'indicator))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StartCollisionAvoidance-request>))
  "Converts a ROS message object to a list"
  (cl:list 'StartCollisionAvoidance-request
    (cl:cons ':indicator (indicator msg))
))
;//! \htmlinclude StartCollisionAvoidance-response.msg.html

(cl:defclass <StartCollisionAvoidance-response> (roslisp-msg-protocol:ros-message)
  ((error
    :reader error
    :initarg :error
    :type cl:string
    :initform ""))
)

(cl:defclass StartCollisionAvoidance-response (<StartCollisionAvoidance-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StartCollisionAvoidance-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StartCollisionAvoidance-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name AU_UAV_ROS-srv:<StartCollisionAvoidance-response> is deprecated: use AU_UAV_ROS-srv:StartCollisionAvoidance-response instead.")))

(cl:ensure-generic-function 'error-val :lambda-list '(m))
(cl:defmethod error-val ((m <StartCollisionAvoidance-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader AU_UAV_ROS-srv:error-val is deprecated.  Use AU_UAV_ROS-srv:error instead.")
  (error m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StartCollisionAvoidance-response>) ostream)
  "Serializes a message object of type '<StartCollisionAvoidance-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'error))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'error))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StartCollisionAvoidance-response>) istream)
  "Deserializes a message object of type '<StartCollisionAvoidance-response>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StartCollisionAvoidance-response>)))
  "Returns string type for a service object of type '<StartCollisionAvoidance-response>"
  "AU_UAV_ROS/StartCollisionAvoidanceResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartCollisionAvoidance-response)))
  "Returns string type for a service object of type 'StartCollisionAvoidance-response"
  "AU_UAV_ROS/StartCollisionAvoidanceResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StartCollisionAvoidance-response>)))
  "Returns md5sum for a message object of type '<StartCollisionAvoidance-response>"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StartCollisionAvoidance-response)))
  "Returns md5sum for a message object of type 'StartCollisionAvoidance-response"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StartCollisionAvoidance-response>)))
  "Returns full string definition for message of type '<StartCollisionAvoidance-response>"
  (cl:format cl:nil "string error~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StartCollisionAvoidance-response)))
  "Returns full string definition for message of type 'StartCollisionAvoidance-response"
  (cl:format cl:nil "string error~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StartCollisionAvoidance-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'error))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StartCollisionAvoidance-response>))
  "Converts a ROS message object to a list"
  (cl:list 'StartCollisionAvoidance-response
    (cl:cons ':error (error msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'StartCollisionAvoidance)))
  'StartCollisionAvoidance-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'StartCollisionAvoidance)))
  'StartCollisionAvoidance-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartCollisionAvoidance)))
  "Returns string type for a service object of type '<StartCollisionAvoidance>"
  "AU_UAV_ROS/StartCollisionAvoidance")