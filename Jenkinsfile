pipeline {
  agent any

  stages {
    stage("core_lib_build") {
      steps {
        cd src
        make core_lib
      }
    }
    stage("core_test") {
      steps {
        cd src
        make core_test
      }
    }
  }
}
