; Auto-generated. Do not edit!


(cl:in-package AU_UAV_ROS-srv)


;//! \htmlinclude StartXbeeIO-request.msg.html

(cl:defclass <StartXbeeIO-request> (roslisp-msg-protocol:ros-message)
  ((indicator
    :reader indicator
    :initarg :indicator
    :type cl:string
    :initform ""))
)

(cl:defclass StartXbeeIO-request (<StartXbeeIO-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StartXbeeIO-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StartXbeeIO-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name AU_UAV_ROS-srv:<StartXbeeIO-request> is deprecated: use AU_UAV_ROS-srv:StartXbeeIO-request instead.")))

(cl:ensure-generic-function 'indicator-val :lambda-list '(m))
(cl:defmethod indicator-val ((m <StartXbeeIO-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader AU_UAV_ROS-srv:indicator-val is deprecated.  Use AU_UAV_ROS-srv:indicator instead.")
  (indicator m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StartXbeeIO-request>) ostream)
  "Serializes a message object of type '<StartXbeeIO-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'indicator))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'indicator))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StartXbeeIO-request>) istream)
  "Deserializes a message object of type '<StartXbeeIO-request>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StartXbeeIO-request>)))
  "Returns string type for a service object of type '<StartXbeeIO-request>"
  "AU_UAV_ROS/StartXbeeIORequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartXbeeIO-request)))
  "Returns string type for a service object of type 'StartXbeeIO-request"
  "AU_UAV_ROS/StartXbeeIORequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StartXbeeIO-request>)))
  "Returns md5sum for a message object of type '<StartXbeeIO-request>"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StartXbeeIO-request)))
  "Returns md5sum for a message object of type 'StartXbeeIO-request"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StartXbeeIO-request>)))
  "Returns full string definition for message of type '<StartXbeeIO-request>"
  (cl:format cl:nil "string indicator~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StartXbeeIO-request)))
  "Returns full string definition for message of type 'StartXbeeIO-request"
  (cl:format cl:nil "string indicator~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StartXbeeIO-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'indicator))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StartXbeeIO-request>))
  "Converts a ROS message object to a list"
  (cl:list 'StartXbeeIO-request
    (cl:cons ':indicator (indicator msg))
))
;//! \htmlinclude StartXbeeIO-response.msg.html

(cl:defclass <StartXbeeIO-response> (roslisp-msg-protocol:ros-message)
  ((error
    :reader error
    :initarg :error
    :type cl:string
    :initform ""))
)

(cl:defclass StartXbeeIO-response (<StartXbeeIO-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StartXbeeIO-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StartXbeeIO-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name AU_UAV_ROS-srv:<StartXbeeIO-response> is deprecated: use AU_UAV_ROS-srv:StartXbeeIO-response instead.")))

(cl:ensure-generic-function 'error-val :lambda-list '(m))
(cl:defmethod error-val ((m <StartXbeeIO-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader AU_UAV_ROS-srv:error-val is deprecated.  Use AU_UAV_ROS-srv:error instead.")
  (error m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StartXbeeIO-response>) ostream)
  "Serializes a message object of type '<StartXbeeIO-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'error))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'error))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StartXbeeIO-response>) istream)
  "Deserializes a message object of type '<StartXbeeIO-response>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StartXbeeIO-response>)))
  "Returns string type for a service object of type '<StartXbeeIO-response>"
  "AU_UAV_ROS/StartXbeeIOResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartXbeeIO-response)))
  "Returns string type for a service object of type 'StartXbeeIO-response"
  "AU_UAV_ROS/StartXbeeIOResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StartXbeeIO-response>)))
  "Returns md5sum for a message object of type '<StartXbeeIO-response>"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StartXbeeIO-response)))
  "Returns md5sum for a message object of type 'StartXbeeIO-response"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StartXbeeIO-response>)))
  "Returns full string definition for message of type '<StartXbeeIO-response>"
  (cl:format cl:nil "string error~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StartXbeeIO-response)))
  "Returns full string definition for message of type 'StartXbeeIO-response"
  (cl:format cl:nil "string error~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StartXbeeIO-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'error))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StartXbeeIO-response>))
  "Converts a ROS message object to a list"
  (cl:list 'StartXbeeIO-response
    (cl:cons ':error (error msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'StartXbeeIO)))
  'StartXbeeIO-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'StartXbeeIO)))
  'StartXbeeIO-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartXbeeIO)))
  "Returns string type for a service object of type '<StartXbeeIO>"
  "AU_UAV_ROS/StartXbeeIO")