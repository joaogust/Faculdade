package Apps;

import Class.Card;
import Class.Card2;
import Class.Deck;

import java.util.ArrayList;

public class App2 {

    public static void main(String[] args) {

        var card1 = new Card("Copas", "Valete");

        System.out.println(card1);
        card1.setSuit("Paus");
        card1.setRank("Ás");
        System.out.println(card1);

        System.out.println("\n------------------------------\n");

        Card2[] cards = new Card2[5];

        cards[0] = new Card2(Card2.Suit.ESPADAS, Card2.Rank.SETE);
        cards[1] = new Card2(Card2.Suit.COPAS, Card2.Rank.AS);
        cards[2] = new Card2(Card2.Suit.PAUS, Card2.Rank.DAMA);
        cards[3] = new Card2(Card2.Suit.OUROS, Card2.Rank.CINCO);
        cards[4] = new Card2(Card2.Suit.COPAS, Card2.Rank.SEIS);

        for (Card2 n: cards) {
            System.out.format("==> %s\n", n);
        }

        System.out.println("\n------------------------------\n");

        var manilha = new Card2(Card2.Suit.COPAS, Card2.Rank.CINCO);
        System.out.println("- - - - - A manilha é: " + manilha.getRank() + " - - - - -\n");

        System.out.println(Card2.verificarMaior(cards[0], cards[1], manilha));
        System.out.println(Card2.verificarMaior(cards[3], cards[2], manilha));
        System.out.println(Card2.verificarMaior(cards[4], cards[1], manilha));
        System.out.println(Card2.verificarMaior(cards[0], cards[3], manilha));
        System.out.println(Card2.verificarMaior(cards[0], cards[0], manilha));

        System.out.println("\n------------------------------\n");

        var baralho = new Deck();

        int i = 1;
        System.out.println("Cartas do Baralho:\n");
        baralho.imprimir();
    }
}
