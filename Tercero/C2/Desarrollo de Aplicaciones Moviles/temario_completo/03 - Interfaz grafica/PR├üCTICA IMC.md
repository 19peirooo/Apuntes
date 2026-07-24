# PRÁCTICA: IMC

Status: Not started
🪴 Units: 3. Interfaz gráfica (../Unidades/3%20Interfaz%20gr%C3%A1fica%20c91eeadeed708332b4c50158c00c238d.md)

Realiza una aplicación para el cálculo del IMC de una persona. Para ello la aplicación contará con las siguientes activitys.

- MainActivity: Donde aparecerá un formulario de introducción de datos para poder meter el peso con un editText donde solo se podrán meter números, altura con un editText donde solo se podrán meter números y sexo (M/F) mediante un grupo de radios. La forma de introducirlo será como la pantalla que se adjunta.
    
    En el caso de que alguno de los datos no esté introducido, al pulsar el botón de evaluar IMC saltará un aviso en formato Snackbar
    

Una vez pulsado el botón,  si todos los elementos están rellenos de forma correcta, se arrancará la segunda pantalla

- SecondActivity: aparecerá en un texto el IMC obtenido, junto con un mensaje de tu estado físico y el icono correspondiente a tu estado.

![Untitled](PR%C3%81CTICA%20IMC/Untitled.png)

![Untitled](PR%C3%81CTICA%20IMC/Untitled%201.png)

Para poder hacer el cálculo del IMC se utiliza la siguiente fórmula:

IMC = peso (kg) / altura2 (m)

Las tablas diferenciadas por sexo para poder hacer el cálculo son las siguientes

IMC    Estado HOMBRES

Por debajo de 18.5    Bajo peso

18,5–24,9    Peso normal

25.0–29.9    Pre-obesidad o Sobrepeso

30.0–34.9    Obesidad clase I

35,0–39,9    Obesidad clase II

Por encima de 40    Obesidad clase III

IMC    Estado MUJERES

Por debajo de 16.5    Bajo peso

16,5–22,9    Peso normal

23.0–25.9    Pre-obesidad o Sobrepeso

26.0–30.9    Obesidad clase I

31,0–33,9    Obesidad clase II

Por encima de 34    Obesidad clase III

Las imágenes para poder completar la práctica son las siguientes:

[estados.zip](PR%C3%81CTICA%20IMC/estados.zip)