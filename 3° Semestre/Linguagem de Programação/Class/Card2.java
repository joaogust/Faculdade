package Class;

public class Card2 {

    public enum Suit {
        PAUS(4), COPAS(3), ESPADAS(2), OUROS(1);

        int peso;

        Suit(int peso) {
            this.peso = peso;
        }
    }

    public enum Rank {
        AS(11), DOIS(12), TRES(13), QUATRO(1), CINCO(2), SEIS(3), SETE(4),
        OITO(5), NOVE(6), DEZ(7), VALETE(8), DAMA(9), REI(10);

        int peso;

        Rank(int peso) {
            this.peso = peso;
        }

        private void setPeso(int peso) {
            this.peso = peso;
        }
    }

    private final Suit suit;
    private final Rank rank;

    public Card2(Suit suit, Rank rank) {
        this.suit = suit;
        this.rank = rank;
    }

    public Suit getSuit() {
        return suit;
    }

    public Rank getRank() {
        return rank;
    }

    @Override
    public String toString() {
        return "Card2{" +
                "suit='" + suit + '\'' +
                ", rank='" + rank + '\'' +
                '}';
    }
    public String toString2() {
        return rank + " de " + suit;
    }

    public static String verificarMaior(Card2 a, Card2 b, Card2 manilha) {
        if (manilha.rank.peso == a.rank.peso)
            a.rank.setPeso(14);
        if (manilha.rank.peso == b.rank.peso)
            b.rank.setPeso(14);

        if(a.rank.peso > b.rank.peso) {
            return "A carta (" + a.toString2() + ") é maior que (" + b.toString2() + ")";
        } else if(a.rank.peso < b.rank.peso) {
            return "A carta (" + b.toString2() + ") é maior que (" + a.toString2() + ")";
        } else {
            if(a.suit.peso > b.suit.peso) {
                return "A carta (" + a.toString2() + ") é maior que (" + b.toString2() + ")";
            } else if(a.suit.peso < b.suit.peso) {
                return "A carta (" + b.toString2() + ") é maior que (" + a.toString2() + ")";
            } else {
                return "As cartas são iguais";
            }
        }
    }
}
