# ESE101
Embedded Systems Essentials with Arm: Getting Started

Course of edX provided by ArmEducation  
https://www.edx.org/course/embedded-systems-essentials-with-arm-getting-started

## installation of Docker Desktop (for Ubuntu)
Docker Desktop is essential for running Mbed Simulator.  
[refer to this website](https://docs.docker.com/engine/install/ubuntu/)

1. Update the apt package index and install packages to allow apt to use a repository over HTTPS:
```
 $ sudo apt-get update

 $ sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg \
    lsb-release
```

2. Add Docker’s official GPG key:
```
$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg
```

3. Set up the stable repository. `nightly` can be replaced with `test`  
[more about 'nightly' and 'test'](https://docs.docker.com/engine/install/)

for x86_64 / amd64
```
echo \
  "deb [arch=amd64 signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable nightly" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
```
for armhf
```
 echo \
  "deb [arch=armhf signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable nightly" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
```

for arm64
```
echo \
  "deb [arch=arm64 signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable nightly" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
```

## installation for Docker Engine
1.Update the apt package index, and install the latest version of Docker Engine and containerd, or go to the next step to install a specific version:
```
$ sudo apt-get update
$ sudo apt-get install docker-ce docker-ce-cli containerd.io
```
2.To install a specific version of Docker Engine, list the available versions in the repo, then select and install:

a. List the versions available in your repo:
```
$ apt-cache madison docker-ce
```
b. Install a specific version using the version string from the second column, for example, `5:18.09.1~3-0~ubuntu-xenial`
```
$ sudo apt-get install docker-ce=<VERSION_STRING> docker-ce-cli=<VERSION_STRING> containerd.io
 ```
**struggled a bit in this process for me.**
It worked if I typed command
```
$ sudo apt-get install docker-ce=18.06.1~ce~3-0~ubuntu containerd.io
```

 
c. Verify that Docker Engine is installed correctly by running the hello-world image.
```
$ sudo docker run hello-world
```
