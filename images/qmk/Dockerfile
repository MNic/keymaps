FROM bitnami/python:3.10.10-debian-11-r4

USER root

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install gcc-avr -y
RUN apt install binutils -y
RUN apt install avr-libc -y
RUN apt install uisp -y
RUN apt-get install gcc-arm-none-eabi -y
RUN apt-get install avrdude -y
RUN apt-get install dfu-programmer -y
RUN apt-get install dfu-util -y

RUN useradd model --system --uid 1001 --create-home
USER 1001
RUN pip install qmk;
RUN mkdir /home/model/qmk_firmware
RUN chown -R model:model /home/model/qmk_firmware

ENV PATH="/home/model/.local/bin:$PATH"
RUN qmk setup -H /home/model/qmk_firmware -y
WORKDIR /home/model/qmk_firmware

