package Class;

import java.util.ArrayList;
import Class.Card2;

public class Deck {

    private ArrayList<Card2> cards;

    public Deck() {
        cards = new ArrayList<Card2>();

        for (Card2.Suit suit: Card2.Suit.values()) {
            for (Card2.Rank rank: Card2.Rank.values()) {
                cards.add(new Card2(suit, rank));
            }
        }
    }

    public Card2 drawCard() {
        return this.cards.remove(this.cards.size() - 1);
    }

    public void imprimir() {
        for (Card2 n: cards) {
            System.out.println(n.toString2());
        }
    }
}
