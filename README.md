# S4 Project - EPITA

## Orion Nebula

### Software description:
- **Original author(s):** Tom Termaat, André Hoang, Albert El Helou, Adrien Hicaubert
- **Developer(s):** Orion
- **Operating system:** Linux
- **Type:** Raster graphics editor
- **Website:** https://orion-projects.wixsite.com/orion

### Description:
*Nebula* is a **computer-assisted editing, processing and drawing software**. It can be mainly used for **processing digital photographs**, but can also be used to **create images from scratch**.

## Repo content

### Nebula-S4

#### The directory `project-files` contains all the folders and files necessary for the correct functioning of the software:
- `cache/`: Contains temporary files stored by the software.
- `src/`: Contains source codes of the sofware.
- `Makefile`: Provided to build the software easely.

#### The directory `resources` contains files for the presentations.

#### The directory `test-files` contains files examples for the software.

## Manual

### Prerequisites:
- GTK: https://www.gtk.org/
- LibGD: https://libgd.github.io/

### Installation:

#### Make sure you have installed the `Prerequisites`
- *`sudo apt-get update`*
- *`sudo apt-get install -y libgtk-3-dev libgd-dev`*

#### Go to `Nebula-S4/project-files/`
- Inside the `Nebula-S4/` directory, you can use the command: *`cd project-files`*.

#### Compile the code by using the `Makefile`
- You can use the command: *`make`* to do so.

#### Run the application
- You can use the command: *`./nebula`* to do so.

