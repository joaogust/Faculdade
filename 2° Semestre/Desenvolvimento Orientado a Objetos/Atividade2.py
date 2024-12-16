class Cadastro:
    def __init__(self, nome, email):
        self.nome = nome
        self.email = email

def validar_email(email):
    if not isinstance(email, str):
        raise ValueError("O e-mail deve ser uma string.")
    if email.count("@") != 1:
        raise ValueError("Erro no e-mail: O e-mail deve conter exatamente um '@'.")
    if not email.split('@')[0].isalnum():
        raise ValueError("Erro no e-mail: O prefixo do e-mail deve conter apenas letras e números.")
    if not (email.endswith(".com") or email.endswith(".org")):
        raise ValueError("Erro no e-mail: O e-mail deve terminar com '.com' ou '.org'.")
    return email    

def formatar_nome(nome):
    if not isinstance(nome, str):
        raise ValueError("Erro no nome: O nome deve conter apenas letras.")
    nome = nome.strip().title()  
    if any(char.isdigit() for char in nome): 
        raise ValueError("Erro no nome: O nome deve conter apenas letras.")
    if not nome.replace(" ", "").isalpha():
        raise ValueError("Erro no nome: O nome deve conter apenas letras.")
    return nome


def formatar(cadastro):
    try:
        cadastro.email = validar_email(cadastro.email)
    except ValueError as e:
        print(e)
        return False
    try:
        cadastro.nome = formatar_nome(cadastro.nome)
    except ValueError as e:
        print(e)
        return False  
    return True 


def main():
    nome = input("Digite seu nome completo: ")
    email = input("Digite seu email: ")

    usuario = Cadastro(nome, email)
    
    if formatar(usuario):
        print(f"\nNome formatado: {usuario.nome}")
        print(f"E-mail válido: {usuario.email}")

if __name__ == "__main__":
    main()
