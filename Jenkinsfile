pipeline {
  agent any

  stages {
    stage("core_lib_build") {
      steps {
        echo "Start build core lib"
        sh 'cd ./src'
        sh 'make build/core_lib.a'
      }
    }
    stage("core_test") {
      steps {
        echo "Start build core test"
        fir('src') {
          sh 'make core_test'
        }
      }
    }
  }
}
