FROM ubuntu:latest

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get clean && apt-get update -y && apt-get install curl nodejs npm -y --no-install-recommends

#update nodejs
RUN npm install n -g && n stable
RUN npm config set strict-ssl false

# install cspell
RUN npm install -g cspell 

WORKDIR /home/cdc-assemblyscript-linter