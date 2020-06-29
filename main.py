################################## IMPORTACION DE LIBRERIAS NECESARIAS PARA EL FUNCIONAMIENTO DEL SISTEMA #######################################

import network
import socket 
import machine
from machine import UART
import time
from machine import Pin

################################################################################################################################################

 

uart = UART(0, 9600)            ##  ELECCION DE LA TASA DE TRANSMISION CON LA QUE SE TRABAJARA            
uart.init(9600, bits=8, parity=None, stop=1) ##SE ELIGEN PARAMETROS TALES COMO EL NUMERO DE BITS A RECIBIR, LA PARIDAD Y EL NUMERO DE BITS DE PARADA


################################################ CONEXION DE LA TARJETA A UNA RED WIFI ###########################################################

wlan = network.WLAN(network.STA_IF)
wlan.active(True)
wlan.ifconfig(('192.168.0.105', '255.255.255 .0', '192.168.0.1', '8.8.8.8'))## SE ASIGNA UNA IP FIJA A LA TARJETA (192.168.0.105)
ssid = 'VESTA'                  ##         NOMBRE DE LA RED WIFI A LA QUE SE CONECTARA
password = 'VESTA2019'          ##         CONTRASENA DE LA RED WIFI A LA QUE SE CONECTARA
if not wlan.isconnected():
  wlan.connect(ssid, password)
  while not wlan.isconnected():
    pass
  
#################################################################################################################################################

exec(open("pruebaht.py").read()) ## EJECUCCION DEL CODIGO CON EL CUAL SE RECIBIRAN LOS DATOS DE LA INTERFAZ