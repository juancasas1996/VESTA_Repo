
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) ## SE CREA EL SOCKET
s.bind(('', 80)) ## SE ENLAZA AL PUERTO 80 DEL COMPUTADOR, DEJANDO EL CAMPO DE LA IP LIBRE PARA QUE OTROS COMPUTADORES DE LA MISMA RED PUEDAN ENVIAR SOLICITUDES
s.listen(5) # SE COLOCA EL SOCKET EN MODO ESCUCHA

## SE INICIALIZAN LAS VARIABLES A UTILIZAR EN 0
var1 = 0
var2 = 0
var3 = 0
var4 = 0
var5 = 0
var6 = 0
var7 = 0
var8 = 0
var9 = 0
 
################################################################################################################################################
while True:     ##  LOOP INFINITO

    conn, addr = s.accept()  ## SE ESTABLECE LA CONEXION CON EL CLIENTE
    request = conn.recv(4096)
    request = str(request)
    if len(request) < 23:
     pass
    else:
        variable = request[23]
        if variable == '1':
            var1 = 1
            var2 = 0
            var3 = 0
            var4 = 0
            var5 = 0 
            
        if variable == '2':
            var1 = 0 
            var2 = 1
            var3 = 0
            var4 = 0
            var5 = 0
            
        if variable == '3':
            var1 = 0
            var2 = 0
            var3 = 1
            var4 = 0
            var5 = 0
            var6 = 0
            var7 = 0
            var8 = 0
            
        if variable == '4':
            var1 = 0
            var2 = 0
            var3 = 0
            var4 = 1
            var5 = 0
            
        if variable == '5':
            var1 = 0
            var2 = 0
            var3 = 0
            var4 = 0
            var5 = 1
            
            
        if variable == '6':
            var6 = 1
            var7 = 0
            var8 = 0
            
        if variable == '7':
            var6 = 0
            var7 = 1
            var8 = 0
            
        if variable == '8':
            var6 = 0
            var7 = 0
            var8 = 1

        if variable == '9':
            var1 = 0
            var2 = 0
            var3 = 0
            var4 = 0
            var5 = 0
            var6 = 0
            var7 = 0
            var8 = 0
            var9 = 1
            
        if (var1 ==1)and(var6==1):
            uart.write('a') 
            var1=0
            var6=0
            
        if (var1 ==1)and(var7==1):
            uart.write('c') 
            var1=0
            var7=0
            
        if (var1 ==1)and(var8==1):
            uart.write('b')
            var1=0
            var8=0
            
        if (var2 ==1)and(var6==1):
            uart.write('d')
            var2=0
            var6=0
            
        if (var2 ==1)and(var7==1):
            uart.write('f')
            var2=0
            var7=0
            
        if (var2 ==1)and(var8==1):
            uart.write('e')
            var2=0
            var8=0
            
        if (var3 ==1):
            uart.write('g')
            var3=0
            
        if (var4 ==1)and(var6==1):
            uart.write('h')
            var4=0
            var6=0
            
        if (var4 ==1)and(var7==1):
            uart.write('j')
            var4=0
            var7=0
            
        if (var4 ==1)and(var8==1):
            uart.write('i')
            var4=0
            var8=0
            
        if (var5 ==1)and(var6==1):
            uart.write('k')
            var5=0
            var6=0
            
        if (var5 ==1)and(var7==1):
            uart.write('m')
            var5=0
            var7=0
            
        if (var5 ==1)and(var8==1):
            uart.write('l')
            var5=0
            var8=0
            
        if (var9 == 1):
            uart.write('n')
            var9 = 0
            
    # print (variable)