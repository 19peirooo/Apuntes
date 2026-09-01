// Funcion auxiliar para cambiar el . decimal por , y que Excel pueda manejar el volcado de salida

char *replacedot(char *str)
{
  int k;
  for (k=0; str[k]!='\0'; k++ )
    if (str[k] == '.')
	str[k] = ',';
  return(str);
}
