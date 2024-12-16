from abc import ABC, abstractmethod
import re

# Classe abstrata
class Evento(ABC):
    def __init__(self, nome, data, local):
        self._nome = nome
        self._data = data
        self._local = local

    @property
    def nome(self):
        return self._nome

    @nome.setter
    def nome(self, nome):
        self._nome = nome

    @property
    def data(self):
        return self._data

    @data.setter
    def data(self, data):
        if not re.match(r'\d{2}/\d{2}/\d{4}', data):
            raise ValueError("Data inválida.")
        self._data = data

    @property
    def local(self):
        return self._local

    @local.setter
    def local(self, local):
        self._local = local

    @abstractmethod
    def detalhes(self):
        pass


# Subclasse Congresso
class Congresso(Evento):
    def __init__(self, nome, data, local, n_trabalhos):
        super().__init__(nome, data, local)
        self._n_trabalhos = n_trabalhos

    @property
    def n_trabalhos(self):
        return self._n_trabalhos

    @n_trabalhos.setter
    def n_trabalhos(self, n_trabalhos):
        if not isinstance(n_trabalhos, int) or n_trabalhos <= 0:
            raise ValueError("O número de trabalhos deve ser positivo.")
        self._n_trabalhos = n_trabalhos

    def detalhes(self):
        return f"CONGRESSO\nNome: {self.nome}\nData: {self.data}\nLocal: {self.local}\nTrabalhos: {self.n_trabalhos}\n"


# Subclasse Palestra
class Palestra(Evento):
    def __init__(self, nome, data, local, palestrante):
        super().__init__(nome, data, local)
        self._palestrante = palestrante

    @property
    def palestrante(self):
        return self._palestrante

    @palestrante.setter
    def palestrante(self, palestrante):
        self._palestrante = palestrante

    def detalhes(self):
        return f"PALESTRA\nNome: {self.nome}\nData: {self.data}\nLocal: {self.local}\nPalestrante: {self.palestrante}\n"


# Subclasse Workshop
class Workshop(Evento):
    def __init__(self, nome, data, local, vagas):
        super().__init__(nome, data, local)
        self._vagas = vagas

    @property
    def vagas(self):
        return self._vagas

    @vagas.setter
    def vagas(self, vagas):
        if not isinstance(vagas, int) or vagas <= 0:
            raise ValueError("O número de vagas deve ser um inteiro positivo.")
        self._vagas = vagas

    def detalhes(self):
        return f"WORKSHOP\nNome: {self.nome}\nData: {self.data}\nLocal: {self.local}\nVagas: {self.vagas}\n"


# Função para mostrar detalhes do evento
def mostrar_detalhes_do_evento(evento):
    print(evento.detalhes())


# Teste com instâncias
congresso = Congresso(nome="Congresso IFSP", data="31/12/2024", local="IFSP, Campus São Paulo", n_trabalhos=100)
palestra = Palestra(nome="Inteligência Artificial", data="31/12/2024", local="IFSP, Campus São Paulo", palestrante="João")
workshop = Workshop(nome="Computação Quântica", data="31/12/2024", local="IFSP, Campus São Paulo", vagas=1000)

# Mostrar detalhes dos eventos
mostrar_detalhes_do_evento(congresso)
mostrar_detalhes_do_evento(palestra)
mostrar_detalhes_do_evento(workshop)
