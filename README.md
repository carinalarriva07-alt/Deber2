Nombre completo
Ana Carina Larriva Barrezueta
Curso
NRC 2684
Descripción breve del ejercicio
    Es un programa en que permite convertir divisas entre USD (dólares) y EUR (euros). El programa solicita al usuario ingresar las monedas base y cotizada, la tasa de cambio y múltiples montos a convertir. Además, genera un timestamp formateado con la fecha y hora proporcionada por el usuario. Presenta un reporte final con los resultados de la conversión y las tasas inversas.
Explicación clara de la lógica del programa
1.	Configuración inicial
o	Se da la bienvenida al usuario y se explica el propósito del programa.
2.	Ingreso de divisas
o	El usuario debe ingresar la divisa base y la divisa cotizada (solo se aceptan "USD" o "EUR").
o	Se valida que la entrada tenga exactamente 3 caracteres y que sean letras.
o	Si la entrada es incorrecta, se solicita nuevamente hasta que sea válida.
3.	Ingreso de la tasa de cambio
o	Se pide la tasa de cambio entre las dos divisas seleccionadas.
o	Se valida que la tasa sea un número positivo mayor que cero.
o	Se calcula automáticamente la tasa inversa (1 dividido para la tasa ingresada).
4.	Ingreso de montos base
o	El usuario puede ingresar múltiples montos en la divisa base.
o	Se valida que cada monto sea un número positivo.
o	El ingreso termina cuando el usuario escribe "X".
o	Los montos válidos se almacenan en un vector (lista) para su posterior conversión.
5.	Generación del timestamp
o	Se solicita al usuario ingresar año, mes, día, hora, minutos y si es AM o PM.
o	Con snprintf se construye un timestamp formateado en el estilo: 
o	AAAA-MM-DD HH:MM AM/PM
6.	Reporte final
o	Se imprime el timestamp.
o	Se muestra el par de divisas seleccionado.
o	Se presentan las tasas de cambio en ambas direcciones (base → cotizada y cotizada → base).
o	Se listan los montos ingresados en la divisa base y sus equivalentes convertidos en la divisa cotizada.
o	Al final, se pregunta si el usuario desea continuar o salir del programa.
7.	Finalización
o	Si el usuario decide salir, se muestra un mensaje de agradecimiento por usar el conversor.
