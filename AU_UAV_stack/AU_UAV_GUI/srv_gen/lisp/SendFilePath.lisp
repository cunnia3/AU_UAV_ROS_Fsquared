; Auto-generated. Do not edit!


(cl:in-package AU_UAV_GUI-srv)


;//! \htmlinclude SendFilePath-request.msg.html

(cl:defclass <SendFilePath-request> (roslisp-msg-protocol:ros-message)
  ((filename
    :reader filename
    :initarg :filename
    :type cl:string
    :initform ""))
)

(cl:defclass SendFilePath-request (<SendFilePath-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SendFilePath-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SendFilePath-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name AU_UAV_GUI-srv:<SendFilePath-request> is deprecated: use AU_UAV_GUI-srv:SendFilePath-request instead.")))

(cl:ensure-generic-function 'filename-val :lambda-list '(m))
(cl:defmethod filename-val ((m <SendFilePath-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader AU_UAV_GUI-srv:filename-val is deprecated.  Use AU_UAV_GUI-srv:filename instead.")
  (filename m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SendFilePath-request>) ostream)
  "Serializes a message object of type '<SendFilePath-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'filename))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'filename))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SendFilePath-request>) istream)
  "Deserializes a message object of type '<SendFilePath-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'filename) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'filename) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SendFilePath-request>)))
  "Returns string type for a service object of type '<SendFilePath-request>"
  "AU_UAV_GUI/SendFilePathRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SendFilePath-request)))
  "Returns string type for a service object of type 'SendFilePath-request"
  "AU_UAV_GUI/SendFilePathRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SendFilePath-request>)))
  "Returns md5sum for a message object of type '<SendFilePath-request>"
  "fe8131f61ada79495e0d839037fe5bd9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SendFilePath-request)))
  "Returns md5sum for a message object of type 'SendFilePath-request"
  "fe8131f61ada79495e0d839037fe5bd9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SendFilePath-request>)))
  "Returns full string definition for message of type '<SendFilePath-request>"
  (cl:format cl:nil "string filename~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SendFilePath-request)))
  "Returns full string definition for message of type 'SendFilePath-request"
  (cl:format cl:nil "string filename~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SendFilePath-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'filename))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SendFilePath-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SendFilePath-request
    (cl:cons ':filename (filename msg))
))
;//! \htmlinclude SendFilePath-response.msg.html

(cl:defclass <SendFilePath-response> (roslisp-msg-protocol:ros-message)
  ((error
    :reader error
    :initarg :error
    :type cl:string
    :initform ""))
)

(cl:defclass SendFilePath-response (<SendFilePath-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SendFilePath-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SendFilePath-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name AU_UAV_GUI-srv:<SendFilePath-response> is deprecated: use AU_UAV_GUI-srv:SendFilePath-response instead.")))

(cl:ensure-generic-function 'error-val :lambda-list '(m))
(cl:defmethod error-val ((m <SendFilePath-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader AU_UAV_GUI-srv:error-val is deprecated.  Use AU_UAV_GUI-srv:error instead.")
  (error m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SendFilePath-response>) ostream)
  "Serializes a message object of type '<SendFilePath-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'error))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'error))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SendFilePath-response>) istream)
  "Deserializes a message object of type '<SendFilePath-response>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SendFilePath-response>)))
  "Returns string type for a service object of type '<SendFilePath-response>"
  "AU_UAV_GUI/SendFilePathResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SendFilePath-response)))
  "Returns string type for a service object of type 'SendFilePath-response"
  "AU_UAV_GUI/SendFilePathResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SendFilePath-response>)))
  "Returns md5sum for a message object of type '<SendFilePath-response>"
  "fe8131f61ada79495e0d839037fe5bd9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SendFilePath-response)))
  "Returns md5sum for a message object of type 'SendFilePath-response"
  "fe8131f61ada79495e0d839037fe5bd9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SendFilePath-response>)))
  "Returns full string definition for message of type '<SendFilePath-response>"
  (cl:format cl:nil "string error~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SendFilePath-response)))
  "Returns full string definition for message of type 'SendFilePath-response"
  (cl:format cl:nil "string error~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SendFilePath-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'error))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SendFilePath-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SendFilePath-response
    (cl:cons ':error (error msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SendFilePath)))
  'SendFilePath-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SendFilePath)))
  'SendFilePath-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SendFilePath)))
  "Returns string type for a service object of type '<SendFilePath>"
  "AU_UAV_GUI/SendFilePath")