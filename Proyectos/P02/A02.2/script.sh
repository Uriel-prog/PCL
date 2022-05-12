#!bin/bash
echo
echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
echo "++          Probando la entrada/salida de datos              ++"
echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
echo
echo "------------------------------------------------------------------"
echo "| ./MCPV </home/ariake/PCL/dev/CO2 > probabilidades  2> errores  |"
echo "------------------------------------------------------------------" 
echo
./MCPV </home/ariake/PCL/dev/CO2 > probabilidades  2> errores
echo
echo "----------------------------------------"
echo "| ./stee para_cifrar < probabilidades  |"
echo "----------------------------------------"
echo
./stee para_cifrar < probabilidades
echo
echo "-----------------------------------------------"
echo "| ./encriptador < para_cifrar salida_cifrada  |"
echo "-----------------------------------------------"
echo
./encriptador < para_cifrar salida_cifrada
echo
echo "----------------------"
echo "|   rm para_cifrar   |"
echo "----------------------"
echo
rm para_cifrar
echo
echo "---------------------------------------------------------"
echo "|  ./encriptador < salida_cifrada salida_desencriptada  |"
echo "---------------------------------------------------------"
echo
./desencriptador < salida_cifrada salida_desencriptada
echo

