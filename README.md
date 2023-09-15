# Keymaps

Personal keymaps

## Basic Usage

1. `bash scr/docker_build.sh` - creates a local docker image based on the dockerfile located at `images/qmk`
2. `bash scr/docker_run.sh` - gives access to qmk commands and make for building keyboard firmware from your docker host


### Example

`bash scr/docker_run.sh make tominabox1/le_chiffre/rev2:mnic_miryoku`

This command uses qmk's make inside the image to build a le chiffre keymap.  The bash script wrapper mounts the .build directory inside the image to your local directory structure.  The built .hex file for flashing is left in the local build directory for use when flashing with QMK Toolbox.

For new keymaps, I typically copy the core keyboard out of the qmk firmware github into an appropriate subdirectory in the `qmk_keyboards` directory, modify for my uses and build my firmware using the example above.  