#!/usr/bin/python

import os
import sys
import subprocess

#cecesito la misma cantidad de archivos como la cantidad máxima de threads que vaya a usar

#ACA CREADOR DE ARCHIVOS (siguiendo además aclaraciones de abajo)

#Exp1: creo X (por ahora 8,16) corpus con todas las palabras distintas entre si
#Exp2: doy corpus (original) como tantos threads tenga
#Exp3: aleatorios como tantos threads tenga
#Exp4: todas palabras que empiezen con la mista letra (sumar la letra a cada random?)

#creo las rutas de archivos a pasarles
archivosExp1 = ''
for file in sorted(os.listdir('./')):
	if not('test' in file or 'resultados' in file or 'py' in file):
		archivosExp1 = archivosExp1 + ' ' + str(file)


#corro los tests, puse una copia del ejecutable en cada expi para que pueda ejecutar la lista de archivos facilmente

for i in range(1,16+1):
	for j in range(1,10+1):
		subprocess.call(['./test-6 '+'count_words_c '+str(i)+archivosExp1+' >> ./resultados/count_words_c/Exp1_'+str(j)+'.csv'],shell = True)

for i in range(1,16+1):
	for j in range(1,10+1):
		subprocess.call(['./test-6 '+'count_words_ct '+str(i)+archivosExp1+' >> ./resultados/count_words_ct/Exp1_'+str(j)+'.csv'],shell = True)

for i in range(1,16+1):
	for j in range(1,10+1):
		subprocess.call(['./test-6 '+'maximum '+str(i)+' '+str(i)+archivosExp1+' >> ./resultados/maximum/Exp1_'+str(j)+'.csv'],shell = True)

for i in range(1,16+1):
	for j in range(1,10+1):
		subprocess.call(['./test-6 '+'maximum_cw_c '+str(i)+' '+str(i)+archivosExp1+' >> ./resultados/maximum_cw_c/Exp1_'+str(j)+'.csv'],shell = True)

for i in range(1,16+1):
	for j in range(1,10+1):
		subprocess.call(['./test-6 '+'maximum_cw_ct '+str(i)+' '+str(i)+archivosExp1+' >> ./resultados/maximum_cw_ct/Exp1_'+str(j)+'.csv'],shell = True)
