# Cosmographia

This is a development fork of an old source copy from 2015 of Cosmographia from https://github.com/claurel/cosmographia. For the latest free Cosmographia version go to https://naif.jpl.nasa.gov/naif/cosmographia.html.

# Comet Visualization (planned)

nothing here yet

For now use my comet .json Cosmographia catalog files: https://github.com/isenberg/cosmographia_catalogs

# Building on Ubuntu 20.04 LTS

As this source copy of Cosmographia is quite old, from 2015, you need to build QT4 from the source package available on https://launchpad.net/~rock-core/+archive/ubuntu/qt4. It needs about 10 GB filesystem space. Instructions:

```
mkdir qt4
cd qt4
sudo add-apt-repository ppa:rock-core/qt4
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
cd cosmographia_comets
qmake-qt4 cosmographia.pro
make
```

To start Cosmographia:
```
build/Cosmographia
```
