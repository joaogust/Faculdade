def somar (a, b):
  resultado = a + b
  return resultado
  
def multiplicar (a, b):
  resultado = a * b
  return resultado

def saudar(nome):
  print(f"Olá, {nome}! Seja bem-vindo ao nosso sistema.")

def despedir(nome):
  print(f"Adeus, {nome}! Até a próxima.")

###############################################################

pip install colorama

###############################################################

from meu_pacote.operacoes import somar, multiplicar
from meu_pacote.mensagens import saudar, despedir
from colorama import Fore, Style, init

init(autoreset=True)

nome = input("Digite seu nome: ")
n1 = int(input("Digite o número 1: "))
n2 = int(input("Digite o número 2: "))

soma = somar(n1, n2)
produto = multiplicar(n1, n2)

print(Fore.GREEN + saudar(nome))
print(f"A soma de {n1} + {n2} é igual a {soma}")
print(f"O produto de {n1} * {n2} é igual a {produto}")
print(Fore.YELLOW + despedir(nome))

###############################################################

from colorama import Fore, Style, init

init(autoreset=True)

print(Fore.YELLOW + "Esse texto está amarelo")
print(Fore.GREEN + "Esse texto está verde")
print(Fore.BLUE + "Esse texto está azul")
