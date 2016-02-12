# ft_printf

| type | Format | Sortie |
| -----| ----| ----------|
| s: | char * |
| S: | wchar_t * |
| d: | int |
| i: | int |
| D: | long int |
| u: | unsigned int |
| U: | unsigned long int |
| o: | unsigned int | octal |
| O: | unsigned long int | octal |
| x: | unsigned int | hexa | 
| X: | unsigned long int | hexa |
| p: | void * | hexa (%#x or %#lx) |
| c: | unsigned char |
| C: | unsigned long char |

| drapeaux | action |
| -------- | ------ |
|rien	| justifié à droite et complété à gauche par des espaces |
|-	|justifié à gauche et complété à droite par des espaces |
|+	| les résultats commencent toujours par le signe + ou -
|espace |	le signe n'est affiché que pour les valeurs négatives
|# | (octal 0VAL) (hexa 0xVAL ou 0XVAL) |
