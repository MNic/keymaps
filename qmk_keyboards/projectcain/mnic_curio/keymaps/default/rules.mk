# Copyright 2023 Duke Institute for Health Innovation (DIHI), 
# Duke University School of Medicine, Durham NC. 
# All Rights Reserved 
# 
#  This product includes software developed or owned by Duke Institute for Health Innovation.  
# Redistribution and use in source and binary forms, with or without modification, are not 
# permitted without written permission from DIHI.  
# 
# https://dihi.org

ENCODER_MAP_ENABLE = yes
EXTRAFLAGS += -flto
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = no
SRC += oneshot.c