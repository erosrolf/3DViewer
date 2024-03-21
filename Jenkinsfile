pipeline {
  agent any

  stages {
    stage("core_lib_build") {
      steps {
        echo "Start build core lib"
        cd src
        make core_lib
      }
    }
    stage("core_test") {
      steps {
        echo "Start build core test"
        cd src
        make core_test
      }
    }
  }
}
