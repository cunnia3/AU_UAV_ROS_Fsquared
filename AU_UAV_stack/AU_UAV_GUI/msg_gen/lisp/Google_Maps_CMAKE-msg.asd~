
(cl:in-package :asdf)

(defsystem "Google_Maps_CMAKE-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "TelemetryUpdate" :depends-on ("_package_TelemetryUpdate"))
    (:file "_package_TelemetryUpdate" :depends-on ("_package"))
  ))