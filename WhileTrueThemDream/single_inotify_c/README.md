#dependencias
sudo apt-get install -y glibc-source 


#ejecutar con un & al final  para iniciar la aplicacion background
#ex
../bin/app &


#se imprime el numero de "PID"
[PID] 15376  

#Se cierra la aplicacion con el comando kill -9  'colocar valor de pid'
#ex 
kill -9 15376


