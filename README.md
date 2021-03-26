# ESE101
Embedded Systems Essentials with Arm: Getting Started

Course of edX provided by ArmEducation  
https://www.edx.org/course/embedded-systems-essentials-with-arm-getting-started

## installation of Docker Desktop (for Ubuntu)
Docker Desktop is essential for running Mbed Simulator.  
[refer to this website](https://docs.docker.com/engine/install/ubuntu/)  
[more detailed description of whole process including Windows, Linux and the Trouble Shooting](https://courses.edx.org/assets/courseware/v1/140cdbbc24b2a2414b1026ef508b8653/asset-v1:ArmEducation+EDARMXES1.6x+3T2020+type@asset+block/arm_embed_doc_m2sv1.pdf)
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

## Downloading and Running Mbed Simulatorimage files with Docker Engine

1. Open a terminal command prompt and run the following command to download the necessary Mbed Simulator image files: 
```
sudo docker pull armedu/mbed_sim
```

![Screenshot_2021-03-26 arm_embed_doc_m2sv1 pdf](https://user-images.githubusercontent.com/71170784/112672116-60b03800-8e63-11eb-807c-0f04d6ab8d91.png)

It might take some time to work done. After running the command, you shall see the screen like above.

2. Run Embed Simulaor
```
sudo docker run -p 7829:7829 armedu/mbed_sim
```
![Screenshot_2021-03-26 arm_embed_doc_m2sv1 pdf(1)](https://user-images.githubusercontent.com/71170784/112672510-dc11e980-8e63-11eb-80cd-4f5f69c32873.png)

After running the command, you shall see the screen like above.

3. Open a browser in Ubuntu and enter the following URL:
```
http://localhost:7829/
```
![Screenshot_2021-03-26 arm_embed_doc_m2sv1 pdf(2)](https://user-images.githubusercontent.com/71170784/112672628-fe0b6c00-8e63-11eb-81e3-bd535267be7f.png)

You can check the simulator is working in real time like above picture.

4. ***OPTIONAL commands***
**if you want to check all running docker containers,
```
sudo docker ps
```
**if you want to stop the container**
```
sudo docker container stop <<container id>>
```
**to restart it again,**
```
sudo docker container start <<container id>>
