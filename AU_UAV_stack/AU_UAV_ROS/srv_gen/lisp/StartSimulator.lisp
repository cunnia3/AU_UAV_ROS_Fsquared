; Auto-generated. Do not edit!


(cl:in-package AU_UAV_ROS-srv)


;//! \htmlinclude StartSimulator-request.msg.html

(cl:defclass <StartSimulator-request> (roslisp-msg-protocol:ros-message)
  ((indicator
    :reader indicator
    :initarg :indicator
    :type cl:string
    :initform ""))
)

(cl:defclass StartSimulator-request (<StartSimulator-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StartSimulator-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StartSimulator-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name AU_UAV_ROS-srv:<StartSimulator-request> is deprecated: use AU_UAV_ROS-srv:StartSimulator-request instead.")))

(cl:ensure-generic-function 'indicator-val :lambda-list '(m))
(cl:defmethod indicator-val ((m <StartSimulator-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader AU_UAV_ROS-srv:indicator-val is deprecated.  Use AU_UAV_ROS-srv:indicator instead.")
  (indicator m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StartSimulator-request>) ostream)
  "Serializes a message object of type '<StartSimulator-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'indicator))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'indicator))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StartSimulator-request>) istream)
  "Deserializes a message object of type '<StartSimulator-request>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StartSimulator-request>)))
  "Returns string type for a service object of type '<StartSimulator-request>"
  "AU_UAV_ROS/StartSimulatorRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartSimulator-request)))
  "Returns string type for a service object of type 'StartSimulator-request"
  "AU_UAV_ROS/StartSimulatorRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StartSimulator-request>)))
  "Returns md5sum for a message object of type '<StartSimulator-request>"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StartSimulator-request)))
  "Returns md5sum for a message object of type 'StartSimulator-request"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StartSimulator-request>)))
  "Returns full string definition for message of type '<StartSimulator-request>"
  (cl:format cl:nil "string indicator~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StartSimulator-request)))
  "Returns full string definition for message of type 'StartSimulator-request"
  (cl:format cl:nil "string indicator~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StartSimulator-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'indicator))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StartSimulator-request>))
  "Converts a ROS message object to a list"
  (cl:list 'StartSimulator-request
    (cl:cons ':indicator (indicator msg))
))
;//! \htmlinclude StartSimulator-response.msg.html

(cl:defclass <StartSimulator-response> (roslisp-msg-protocol:ros-message)
  ((error
    :reader error
    :initarg :error
    :type cl:string
    :initform ""))
)

(cl:defclass StartSimulator-response (<StartSimulator-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StartSimulator-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StartSimulator-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name AU_UAV_ROS-srv:<StartSimulator-response> is deprecated: use AU_UAV_ROS-srv:StartSimulator-response instead.")))

(cl:ensure-generic-function 'error-val :lambda-list '(m))
(cl:defmethod error-val ((m <StartSimulator-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader AU_UAV_ROS-srv:error-val is deprecated.  Use AU_UAV_ROS-srv:error instead.")
  (error m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StartSimulator-response>) ostream)
  "Serializes a message object of type '<StartSimulator-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'error))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'error))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StartSimulator-response>) istream)
  "Deserializes a message object of type '<StartSimulator-response>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StartSimulator-response>)))
  "Returns string type for a service object of type '<StartSimulator-response>"
  "AU_UAV_ROS/StartSimulatorResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartSimulator-response)))
  "Returns string type for a service object of type 'StartSimulator-response"
  "AU_UAV_ROS/StartSimulatorResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StartSimulator-response>)))
  "Returns md5sum for a message object of type '<StartSimulator-response>"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StartSimulator-response)))
  "Returns md5sum for a message object of type 'StartSimulator-response"
  "deeb10c2d9f6cfc01c3e0da763fa0b2b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StartSimulator-response>)))
  "Returns full string definition for message of type '<StartSimulator-response>"
  (cl:format cl:nil "string error~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StartSimulator-response)))
  "Returns full string definition for message of type 'StartSimulator-response"
  (cl:format cl:nil "string error~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StartSimulator-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'error))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StartSimulator-response>))
  "Converts a ROS message object to a list"
  (cl:list 'StartSimulator-response
    (cl:cons ':error (error msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'StartSimulator)))
  'StartSimulator-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'StartSimulator)))
  'StartSimulator-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StartSimulator)))
  "Returns string type for a service object of type '<StartSimulator>"
  "AU_UAV_ROS/StartSimulator")