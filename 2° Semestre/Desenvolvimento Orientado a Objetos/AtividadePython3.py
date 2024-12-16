from abc import ABC, abstractmethod
import re

# Classe abstrata
class Evento(ABC):
    def __init__(self, nome, data, local):
        self.nome = nome
        self.data = data
        self.local = local

        # Método abstrato
        def detalhes(self):
            pass

        @nome.setter
        def nome(self, nome):
            self.nome = nome

        @property
        def nome(self):
            return self.nome

        @data.setter
        def data(self, data):
            if not re.match(r'\d{2}/\d{2}/\d{4}', data):
                raise ValueError("Data deve estar no formato DD/MM/AAAA.")
            self.data = data

        @property
        def data(self):
            return self.data

        @local.setter
        def local(self, local):
            self.local = local

        @property
        def local(self):
            return self.local


# Subclasse Congresso
class Congresso(Evento):
    def __init__(self, nome, data, local, n_trabalhos):
        super().__init__(nome, data, local)
        self.n_trabalhos = n_trabalhos

    @n_trabalhos.setter
    def n_trabalhos(self, n_trabalhos):
        self.n_trabalhos = n_trabalhos

    @property
    def n_trabalhos(self):
        return self.n_trabalhos

    def detalhes(self):
        return f"Nome: {self.nome}\nData: {self.data}\nLocal: {self.local}\nTabalhos: {self.n_trabalhos}"


# Subclasse Palestra
class Palestra(Evento):
    def __init__(self, nome, data, local, palestrante):
        super().__init__(nome, data, local)
        self.palestrante = palestrante

    @palestrante.setter
    def palestrante(self, palestrante):
        self.palestrante = palestrante

    @property
    def palestrante(self):
        return self.palestrante

    def detalhes(self):
        return f"Nome: {self.nome}\nData: {self.data}\nLocal: {self.local}\nPalestrante: {self.palestrante}"


# Subclasse Workshop
class Palestra(Evento):
    def __init__(self, nome, data, local, vagas):
        super().__init__(nome, data, local)
        self.vagas = vagas

    @vagas.setter
    def vagas(self, vagas):
        self.vagas = vagas

    @property
    def vagas(self):
        return self.vagas

    def detalhes(self):
        return f"Nome: {self.nome}\nData: {self.data}\nLocal: {self.local}\nVagas: {self.vagas}"


def mostrarDetalhesDoEvento(evento):
    print(evento.detalhes())

