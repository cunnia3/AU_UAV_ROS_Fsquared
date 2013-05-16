FILE(REMOVE_RECURSE
  "../src/Google_Maps_CMAKE/msg"
  "../src/Google_Maps_CMAKE/srv"
  "../msg_gen"
  "../srv_gen"
  "../msg_gen"
  "../srv_gen"
  "CMakeFiles/rosbuild_premsgsrvgen"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/rosbuild_premsgsrvgen.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
