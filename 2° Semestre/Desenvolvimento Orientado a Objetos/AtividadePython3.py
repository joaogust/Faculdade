from abc import ABC, abstractmethod
import re

class Evento(ABC):
  def __init__(self, nome, data, local):
    self.nome = nome
    self.data = data
    self.local = local

    # Método abstrato
    def detalhes(self):
      pass

    @nome.setter
    def nomeSetter(self, nome):
      self.nome = nome

    # getter
    def nomeGetter(self):
        return self._nome

    @data.setter
    def data(self, data):
        if not re.match(r'\d{2}/\d{2}/\d{4}', data):
            raise ValueError("Data deve estar no formato DD/MM/AAAA.")
        self._data = data

    # getter
    def dataGetter(self):
        return self.data

    @local.setter
    def localSetter(self, local):
      self.local = local

    # getter
    def localGetter(self):
        return self.local
