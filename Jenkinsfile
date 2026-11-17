pipeline {
    agent any

    environment {
        DOCKER_IMAGE = 'your-dockerhub-username/your-app'
        REGISTRY_CREDENTIALS = 'dockerhub-credentials-id'
    }

    stages {

        stage('Checkout') {
            steps {
                git 'https://github.com/your-repo/your-app.git'
            }
        }

        stage('Build Docker Image') {
            steps {
                script {
                    docker.build("${DOCKER_IMAGE}:${env.BUILD_NUMBER}")
                }
            }
        }

        stage('Push to Docker Hub') {
            steps {
                script {
                    docker.withRegistry(
                        'https://registry.hub.docker.com',
                        "${REGISTRY_CREDENTIALS}"
                    ) {
                        docker.image(
                            "${DOCKER_IMAGE}:${env.BUILD_NUMBER}"
                        ).push()
                    }
                }
            }
        }

        stage('Deploy') {
            steps {
                echo 'Deploy stage'
            }
        }
    }
}