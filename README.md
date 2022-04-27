# Cosmographia

Cosmographia is an application for visualization of space missions and Solar System exploration. It uses spacecraft trajectories and planet ephemerides from SPICE kernels to precisely reproduce the geometry of encounters.

Features
* Automatic, multithread downloading of high resolution textures
* Loading and updating of catalog files at run time
* Shadows and reflections on models
* Realistic stars
* Realistic atmospheres
* Automatic update of satellite two-line elements

# Comet Visualization (planned)

This fork by Holger Isenberg https://areo.info is planned to add a visual comet simulation with plasma tail, dust tail, sodium tail, anti tail and trail.

The approximation for the tail syndyne (syndyname) is based on the following papers:
- On the Study of Comet Tails and Models of the Interplanetary Medium
  https://ui.adsabs.harvard.edu/abs/1961ApJ...133.1091B/abstract
- A theory of dust comets. I. Model and equations
  https://ui.adsabs.harvard.edu/abs/1968ApJ...154..327F/abstract
- Motion of Cometary Dust
  https://www.lpi.usra.edu/books/CometsII/7006.pdf

# Building on Ubuntu 20.04 LTS

As this source copy of Cosmographia is quite old, from 2015, you need to install QT4 from https://launchpad.net/~rock-core/+archive/ubuntu/qt4:

```
mkdir qt4
cd qt4
cat > rock-core-ubuntu-qt4-focal.list <<OCHE
#deb https://ppa.launchpadcontent.net/rock-core/qt4/ubuntu focal main
deb-src http://ppa.launchpad.net/rock-core/qt4/ubuntu focal main
OCHE
sudo mv rock-core-ubuntu-qt4-focal.list /etc/apt/sources.list.d/
sudo apt update
sudo apt source qt4-x11
sudo apt build-dep qt4-x11
cd qt4-x11-4.8.7+dfsg
sudo dpkg-buildpackage -us -uc
cd ..
mkdir qt4-debs
mkdir qt4-debs-other
mv qt4-doc* qt4-debs-other/
mv *.deb qt4-debs/
sudo dpkg -i -R qt4-debs
cd ..
```

Using QT4 to build Cosmographia:
```
git clone https://github.com/isenberg/cosmographia_comets.git
cd cosmographia
qmake-qt4 cosmographia.pro
make
```

To start Cosmographia:
```
cosmographia/builds/Cosmographia
```
