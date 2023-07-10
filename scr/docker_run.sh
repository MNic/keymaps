# Copyright 2023 Duke Institute for Health Innovation (DIHI), 
# Duke University School of Medicine, Durham NC. 
# All Rights Reserved. 
# 
# This product includes software developed or owned by Duke Institute for Health Innovation. 
# Redistribution and use in source and binary forms, with or without modification, are not 
# permitted without written permission from DIHI. 
# 
# https://dihi.org

docker run --rm -it \
	-w /home/model/qmk_firmware \
	-v ${PWD}/qmk_keyboards:/home/model/qmk_firmware/keyboards \
	-v ${PWD}/build:/home/model/qmk_firmware/.build \
	-e ALT_GET_KEYBOARDS=true \
    myqmk:latest \
    $@