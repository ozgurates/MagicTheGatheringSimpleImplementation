#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>


class Card{
protected:
    std::string name;
    int manaCost;
    bool isTapped;
    int findWhichClass;
    std::string cardColor;
    bool hasTrample = false;
    bool hasFirstStrike = false;
    int creatureCardHP;
    int creaturecardDamage;
public:
    Card(){}
    Card(std::string s):name(s),isTapped(false){}

    virtual std::string play(std::string s){}

    std::string getName(){return name;}

    void setTappedState(bool x){
        isTapped = x;
    }
    int getClassType(){
        return findWhichClass;
    }
    void setCardTapped(Card& c){
        c.isTapped = true;
    }

    int getDamage(){
        return creaturecardDamage;
    }
    int getHP(){
        return creatureCardHP;
    }

    bool getTrample(){
        return hasTrample;
    }

    bool getFirstStrike(){
        return hasFirstStrike;
    }

    void setHP(int x){
        creatureCardHP = x;
    }

    void setCreatureDamage(int x){
        creaturecardDamage = creaturecardDamage + x;
    }

    void setCreatureHP(int x){
        creatureCardHP = creatureCardHP + x;
    }

    void setTrampleAbility(bool x){
        hasTrample = x;
    }
    void setFirstStrikeAbility(bool x){
        hasFirstStrike = x;
    }

    std::string getCarColor(){
        return cardColor;
    }


};


class landCard : public Card{
//no mana costs for this type
// no color
//can be used to gain mana points
//has tapped untapped state
// when destroyed gets moved to discardPile
//In play phase, the player can playa maximum of ONE land card from his hand.
//we tap land cards to gain mana points
//if you play a land card in first play phase, you cannot play landcard in 2nd play phase
//when a players turn ends, all unused mana points tukenir
//When a player plays a land card, s/he simply moves the card from his/her hand to the in play pile.
//Newly played land cards enter the game as “untapped”
//A player can play only ONE land card each turn, either in phase 3 or phase 5
protected:
    std::string mana;
public:
    landCard(std::string s):Card(s){
        if(s == "Forest") {
            //mana = "G"; //green
            findWhichClass = 1;
            //isTapped = false;
        }
        else if(s == "Island") {
            //mana = "L"; //blue
            findWhichClass = 1;
            //isTapped = false;
        }
        else if(s == "Mountain") {
           //mana = "R"; //red
            findWhichClass = 1;
            //isTapped = false;
        }
        else if(s == "Plains") {
            //mana = "W"; //white
            findWhichClass = 1;
            //isTapped = false;
        }
        else if(s == "Swamp") {
            //mana = "B"; //black
            findWhichClass = 1;
            //isTapped = false;
        }
    }
    virtual std::string play(std::string s)override{
        if (s == "Forest"){
            return "G";
        }
        else if(s == "Island"){
            return "L";
        }
        else if(s == "Mountain"){
            return "R";
        }
        else if(s == "Plains"){
            return "W";
        }
        else if(s == "Swamp"){
            return "B";
        }
    }

};


class creatureCard : public Card{
    //has tapped untapped state
    //when destroyed gets moved to discardPile
    //When a player plays a creature card,s/he moves the card from his/her hand to the in play pile by  paying  its  mana  cost.
    //Newly  played  creature  cards  enter  the  game  as  “untapped”.
    //Then  the  effect  of enchantment cards already in play are applied to this creature card
    //Then  the  effect  of enchantment cards already in play are applied to this creature card
protected:
    bool isDestroyed;
    std::string manaCost;
public:
    creatureCard(std::string s):Card(s){
        if (s == "Soldier"){
            creatureCardHP = 1;
            creaturecardDamage = 1;
            cardColor = "White";
            manaCost = "W";
            findWhichClass = 2;
            //isTapped = false;
        }
        else if(s == "ArmoredPegasus"){
            creatureCardHP = 2;
            creaturecardDamage = 1;
            cardColor = "White";
            manaCost = "1W";
            findWhichClass = 2;
            //isTapped = false;
        }
        else if(s == "WhiteKnight"){
            creatureCardHP = 2;
            creaturecardDamage = 2;
            cardColor = "White";
            manaCost = "WW";
            hasFirstStrike = true;
            findWhichClass = 2;
            //isTapped = false;
        }
        else if(s == "AngryBear"){
            creatureCardHP = 2;
            creaturecardDamage = 3;
            cardColor = "Green";
            manaCost = "2G";
            hasTrample = true;
            findWhichClass = 2;
            //isTapped = false;
        }
        else if(s == "Guard"){
            creatureCardHP = 2;
            creaturecardDamage = 5;
            cardColor = "White";
            manaCost = "2WW";
            findWhichClass = 2;
            //isTapped = false;
        }
        else if(s == "Werewolf"){
            creatureCardHP = 6;
            creaturecardDamage = 4;
            cardColor = "Green";
            manaCost = "2GW";
            hasTrample = true;
            findWhichClass = 2;
            //isTapped = false;
        }
        else if (s == "Skeleton"){
            creatureCardHP = 1;
            creaturecardDamage = 1;
            cardColor = "Black";
            manaCost = "B";
            findWhichClass = 2;
            //isTapped = false;
        }
        else if (s == "Ghost"){
            creatureCardHP = 1;
            creaturecardDamage = 2;
            cardColor = "Black";
            manaCost = "1B";
            findWhichClass = 2;
            //isTapped = false;
        }else if(s == "BlackKnight"){
            creatureCardHP = 2;
            creaturecardDamage = 2;
            cardColor = "Black";
            manaCost = "BB";
            hasFirstStrike = true;
            findWhichClass = 2;
            //isTapped = false;
        }else if(s == "OrcManiac"){
            creatureCardHP = 1;
            creaturecardDamage = 4;
            cardColor = "Red";
            manaCost = "2R";
            findWhichClass = 2;
            //isTapped = false;
        } else if (s == "Hobgoblin"){
            creatureCardHP = 3;
            creaturecardDamage = 3;
            cardColor = "Red";
            manaCost = "1RB";
            findWhichClass = 2;
            //isTapped = false;
        }else if(s == "Vampire"){
            creatureCardHP = 3;
            creaturecardDamage = 6;
            cardColor = "Black";
            manaCost = "3B";
            findWhichClass = 2;
            //isTapped = false;
        }
    }
    virtual std::string play(std::string s){
        if (s == "Soldier"){
            manaCost = "W";
            return manaCost;
        }
        else if(s == "ArmoredPegasus"){
            manaCost = "1W";
            return manaCost;
        }
        else if(s == "WhiteKnight"){
            manaCost = "WW";
            return manaCost;
        }
        else if(s == "AngryBear"){
            manaCost = "2G";
            return manaCost;
        }
        else if(s == "Guard"){
            manaCost = "2WW";
            return manaCost;
        }
        else if(s == "Werewolf"){
            manaCost = "2GW";
            return manaCost;
        }
        else if (s == "Skeleton"){
            manaCost = "B";
            return manaCost;
        }
        else if (s == "Ghost"){
            manaCost = "1B";
            return manaCost;
        }else if(s == "BlackKnight"){
            manaCost = "BB";
            return manaCost;
        }else if(s == "OrcManiac"){
            manaCost = "2R";
            return manaCost;
        } else if (s == "Hobgoblin"){
            manaCost = "1RB";
            return manaCost;
        }else if(s == "Vampire"){
            manaCost = "3B";
            return manaCost;
        }

    }



};

class enhancementCard : public Card{
    //when destroyed gets moved to discardPile
    //When aplayer plays an enchantment card,s/he moves the card from his/her hand to the in play pile by paying its mana cost.
    //Enchantment cards do NOT have “untapped”/ “tapped” status.
    //Then, the effect  of  this  enchantment  card  is  immediately  applied  to  ALL  applicable  creature  cards  in  play
    //If  an enchantment card is destroyed, its effect is reversely applied to ALL applicable creature cards in play.
    //Each enchantmentCard object should have a field to keep its Effect using an Effect object (or its sub-classes)
protected:
    std::string manaCost;
    std::string cardColor;
public:
    enhancementCard(std::string s):Card(s){
        if(s == "Rage"){
            cardColor = "Green";
            manaCost = "G";
            findWhichClass = 3;
        }else if(s == "HolyWar"){
            cardColor = "White";
            manaCost = "1W";
            findWhichClass = 3;
        }else if(s == "HolyLight"){
            cardColor = "White";
            manaCost = "1W";
            findWhichClass = 3;
        }else if(s == "UnholyWar"){
            cardColor = "Black";
            manaCost = "1B";
            findWhichClass = 3;
        }else if(s == "Restrain"){
            cardColor = "Red";
            manaCost = "2R";
            findWhichClass = 3;
        }else if(s == "Slow"){
            cardColor = "Black";
            manaCost = "B";
            findWhichClass = 3;
        }
    }
    virtual std::string play(std::string s){
        if(s == "Rage"){
            manaCost = "G";
            return manaCost;
        }else if(s == "HolyWar"){
            manaCost = "1W";
            return manaCost;
        }else if(s == "HolyLight"){
            manaCost = "1W";
            return manaCost;
        }else if(s == "UnholyWar"){
            manaCost = "1B";
            return manaCost;
        }else if(s == "Restrain"){
            manaCost = "2R";
            return manaCost;
        }else if(s == "Slow"){
            manaCost = "B";
            return manaCost;
        }
    }
};

class sorceryCard : public Card{
    //When a player plays a sorcery card,s/he moves the card from his/her hand to the discardpile by  paying  its  mana  cost
    //  Then,  the  effect  of  this  sorcery  card  is  immediately  applied  to  ALL  applicable creature(s) cards in play and player(s)
    //Each sorceryCard object should have a field to keep its Effect using an Effect object (or its sub-classes)
protected:
    std::string manaCost;
    std::string carColor;
public:
    sorceryCard(std::string s):Card(s){
        if(s == "Disenchant"){
            cardColor = "White";
            manaCost = "1W";
            findWhichClass = 4;
        }else if(s == "LightningBolt"){
            cardColor = "Green";
            manaCost = "1G";
            findWhichClass = 4;
        }else if(s == "Flood"){
            cardColor = "Green";
            manaCost = "1GW";
            findWhichClass = 4;
        }else if(s == "Reanimate"){
            cardColor = "Black";
            manaCost = "B";
            findWhichClass = 4;
        }else if(s == "Plague"){
            cardColor = "Black";
            manaCost = "2B";
            findWhichClass = 4;
        }else if(s == "Terror"){
            cardColor = "Black";
            manaCost = "1B";
            findWhichClass = 4;
        }
    }

    virtual std::string play(std::string s){
        if(s == "Disenchant"){
            manaCost = "1W";
            return manaCost;
        }else if(s == "LightningBolt"){
            manaCost = "1G";
            return manaCost;
        }else if(s == "Flood"){
            manaCost = "1GW";
            return manaCost;
        }else if(s == "Reanimate"){
            manaCost = "B";
            return manaCost;
        }else if(s == "Plague"){
            manaCost = "2B";
            return manaCost;
        }else if(s == "Terror"){
            manaCost = "1B";
            return manaCost;
        }
    }



};


class Player{
protected:
    std::vector<Card*> hand;
    std::vector<Card*> deck;
    std::vector<Card*> discard;
    std::vector<Card*> play;
    int playerHP;
    bool playedLandInFirstRound = false;
    std::string getMana = " ";
    std::string currentMana = " ";
    std::string manaCost = " ";
    std::string holdValueOfMana = " ";
public:

    Player():playerHP(15){
    }

    int getHp(){
        return playerHP;
    }

    void addBeginningSorceryCards(std::vector<sorceryCard*> s){
        deck.insert(deck.end(),s.begin(),s.end());
    }
    void addBeginningCreatureCards(std::vector<creatureCard*> c){
        deck.insert(deck.end(),c.begin(),c.end());
    }
    void addBeginningEnhancementCards(std::vector<enhancementCard*> e){
        deck.insert(deck.end(),e.begin(),e.end());
    }
    void addBeginningLandCards(std::vector<landCard*> l){
        deck.insert(deck.end(),l.begin(),l.end());
    }

    void shuffle(){
        srand(time(0));

        for (int i=0; i<26 ;i++)
        {
            // Random for remaining positions.
            int r = i + (rand() % (26 -i));

            std::swap(deck[i], deck[r]);
        }

    }

    void draw(int x){
        if(hand.size() + x <= 7){
            for (int i = 0; i < x; i++) {
                hand.push_back(deck.at(i)); //push first element of deck to hand
                deck.erase(deck.begin()+0); //then delete that element from deck
            }
        }else{
            std::cout<<"You cannot draw this many cards! "<<std::endl;
        }
    }


    void printCards(){
       for(int i=0;i<hand.size();i++){
           std::cout << hand[i]->getName() << " :" << hand[i]->play(hand[i]->getName()) << std::endl;
       }
    }

    int getCardNumInHand(){
        return hand.size();
    }

    int getCardNumInDeck(){
        return deck.size();
    }

    void setUntapped(){
        for (int i=0;i<hand.size();i++){
            hand[i]->setTappedState(false);
        }
    }

    bool checkIfInHandPile(std::string s){
        bool x = false;
        for (int i =0;i<hand.size();i++){
            if (s == hand[i]->getName()){
                x = true;
                break;
            }
        }
        return x;
    }

    bool checkIfInPlayPile(std::string s){
        bool x = false;
        for (int i =0;i<play.size();i++){
            if (s == play[i]->getName()){
                x = true;
                break;
            }
        }
        return x;
    }

    void addToPlayPile(std::string s){
        bool x;
        for (int i =0;i<hand.size();i++){
            if(s == hand[i]->getName()){
                if (hand[i]->getClassType() == 1) {
                    checkWhichCard(*hand[i]);
                    play.push_back(hand[i]);
                    hand.erase(hand.begin() + i);//delete ith element from handpile
                    break;
                }else{
                    //check if there are enough mana in player then sub that much mana from player then extract that card from hand pile and add play pile.
                    x = checkWhichCard(*hand[i]);
                    if(x){
                        play.push_back(hand[i]);
                        hand.erase(hand.begin() + i);//delete ith element from handpile
                        break;
                    }
                    else{
                        std::cout<<"You don't have enough mana! "<<std::endl;
                        std::cout<<std::endl;
                    }
                }
            }
        }
    }

    void removeFromPlayPile(std::string s){
        for (int i=0;i<play.size();i++){
            if(s == play[i]->getName()){
                play.erase(play.begin()+i);
                break;
            }
        }
    }

    bool checkWhichCard(Card& c){
        if(c.getClassType() == 1){//landcard
           getMana = c.play(c.getName());
           addMana();
           c.setCardTapped(c);
        }
        else if(c.getClassType() == 2){//creaturecard
           manaCost = c.play(c.getName());
           if (subMana()) {
               c.setCardTapped(c);
               return true;
           }else{std::cout<<"Not enough mana card cannot be drawn! "<<std::endl;std::cout<<std::endl;currentMana = holdValueOfMana;printCurrentMana();return false;}
        }
        else if(c.getClassType() == 3){//enhancementcard
             manaCost = c.play(c.getName());
            if (subMana()) {
                c.setCardTapped(c);
                return true;
            }else{std::cout<<"Not enough mana card cannot be drawn! "<<std::endl;std::cout<<std::endl;currentMana = holdValueOfMana;printCurrentMana();return false;}
        }
        else if(c.getClassType() == 4){//sorcerycard
            manaCost = c.play(c.getName());
            if (subMana()) {
                c.setCardTapped(c);
                return true;
            }else{std::cout<<"Not enough mana card cannot be drawn! "<<std::endl;std::cout<<std::endl;currentMana = holdValueOfMana;printCurrentMana();return false;}
        }
    }
    void addMana(){
        currentMana += getMana;
        holdValueOfMana = currentMana;
        printCurrentMana();
    }

    bool subMana(){
        bool z = true;
        char x;
        int a=0;
        if(currentMana != " "){
            std::cout<<"This card's mana cost is: "<<manaCost<<std::endl;
            printCurrentMana();
            if (manaCost[0] == '1' || manaCost[0] == '2'){
                if(manaCost[0] == '1'){
                    if (currentMana.size() >= manaCost.size()) {
                        std::cout<<"Which mana you want to spend for 1 colorless mana? "<<std::endl;
                        std::cin>>x;
                        size_t position = currentMana.find(x);
                        if (position != std::string::npos){
                            currentMana.erase(position,1);
                            printCurrentMana();
                            z = true;
                        }
                        else{
                            std::cout<<"Sorry "<<x<<" not found"<<std::endl;
                            return false;
                        }
                        for (int i=0;i<manaCost.size()-1;i++){
                            std::size_t newPosition = currentMana.find(manaCost[i+1]);
                            if (newPosition != std::string::npos) {
                                currentMana.erase(newPosition, 1);
                                printCurrentMana();
                            } else {
                                std::cout << "sorry " << manaCost[i+1] << " not found." << std::endl;
                                return false;
                            }
                        }
                    }
                    else{return false;}
                }
                else{
                    if (currentMana.size() >= manaCost.size()+1){
                        while (a<2){
                            std::cout<<"Which manas you want to spend for 2 colorless manas? "<<std::endl;
                            std::cin>>x;
                            size_t position = currentMana.find(x);
                            if (position != std::string::npos){
                                currentMana.erase(position,1);
                                printCurrentMana();
                                z = true;
                            }
                            else{
                                std::cout<<"Sorry "<<x<<" not found"<<std::endl;
                                return false;
                            }
                            a++;
                        }
                        for (int i=0;i<manaCost.size()-1;i++){
                            std::size_t newPosition = currentMana.find(manaCost[i+1]);
                            if (newPosition != std::string::npos) {
                                currentMana.erase(newPosition, 1);
                                printCurrentMana();
                                z = true;
                            } else {
                                std::cout << "sorry " << manaCost[i+1] << " not found." << std::endl;
                                return false;
                            }
                        }
                    }
                    else{return false;}

                }
            }
            else{
                for(int i=0;i<manaCost.size();i++){
                    std::size_t pos = currentMana.find(manaCost[i]);
                    if(pos != std::string::npos){
                        currentMana.erase(pos,1);
                        printCurrentMana();
                        z = true;
                    }
                    else{
                        std::cout<<"Sorry "<<manaCost[i] <<" not found"<<std::endl;
                        return false;
                    }
                }

            }

        }
        else{
            std::cout<<"You don't have any mana! "<<std::endl;
            std::cout<<std::endl;
            return false;
        }
        return z;
    }


    void printCurrentMana(){
        std::cout<<"Current manas: "<<currentMana<<std::endl;
        std::cout<<std::endl;
    }

    int checkCardType(std::string s){
        for (int i=0;i<play.size();i++){
            if(s == play[i]->getName()){
                if (play[i]->getClassType() == 1)
                    return 1;
                else if(play[i]->getClassType() == 2)
                    return 2;
                else if (play[i]->getClassType() == 3)
                    return 3;
                else
                    return 4;
            }
        }
    }

    Card& returnCard(std::string s){
        for (int i=0;i<play.size();i++){
            if(s == play[i]->getName()){
                return *play[i];
            }
        }
    }


    void attackPlayer(Card& c,Player& p){
        int x = c.getDamage();
        p.lowerHP(x);
    }

    void lowerHP(int x){
        playerHP -= x;
    }

    void addDefendingCreature(std::string s){
        for (int i=0;i<hand.size();++i){
            if (s == hand[i]->getName()){
                play.push_back(hand[i]);
                break;
            }
        }
    }

    void addTrampleAbility(std::string s){
        for (int i=0;i<play.size();i++){
            if (s == play[i]->getName()){
                play[i]->setTrampleAbility(true);
                std::cout<<"Trample ability has been added to creature "<<play[i]->getName()<<std::endl;
                std::cout<<std::endl;
                break;
            }
        }
    }

    bool hasTrampleAbility(Card& s){
        if(s.getTrample())
            return true;
        else return false;
    }

    bool hasFirstStrikeAbility(Card& s){
        if (s.getFirstStrike())
            return true;
        else return false;
    }

    void printCreatureCardsInHand(){
        for (int i=0;i<hand.size();++i){
            if (hand[i]->getClassType() == 2){
                std::cout<<hand[i]->getName()<<std::endl;
            }
        }
        std::cout<<std::endl;
    }
    void printCreatureCardsInPlay(){
        for (int i = 0; i <play.size() ; ++i) {
            if (play[i]->getClassType() == 2)
                std::cout<<play[i]->getName()<<std::endl;
        }
        std::cout<<std::endl;
    }

    void attackDefendingCreature(Card& c1,Card& c2){
        int damage1 = c1.getDamage();
        int damage2 = c2.getDamage();
        int hp1 = c1.getHP();
        int hp2 = c2.getHP();

        hp2 = hp2 - damage1;
        hp1 = hp1 - damage2;

        c1.setHP(hp1);
        c2.setHP(hp2);

        std::cout<<"playerA creature has "<<hp1<<" hp left!"<<std::endl;
        std::cout<<"playerB creature has "<<hp2<<" hp left!"<<std::endl;
    }

    bool isCreatureDead(Card& c){
        if(c.getHP() <=0)
            return true;
        else return false;
    }

    bool isPlayerDead(){
        if (playerHP <= 0)
            return true;
        else return false;
    }

    void firstStrikeAttack(Card& c1, Card c2){
        int hp1 = c1.getHP();
        int hp2 = c2.getHP();
        int dmg1 = c1.getDamage();
        int dmg2 = c2.getDamage();
        hp2 = hp2 - dmg1;
        if(hp2<=0){
            std::cout<<"Creature is dead! "<<std::endl;
            std::cout<<std::endl;
        }
        else{
            hp1 = hp1 - dmg2;
            std::cout<<"Creature 1 has "<<hp1<<" HP left! "<<std::endl;
            std::cout<<"Creature 2 has "<<hp2<<" HP left! "<<std::endl;
        }
    }

    void trampleAttack(Card& c1,Card& c2,Player& p1){
        int hp1 = p1.getHp();
        int hp2 = c2.getHP();
        int dmg1 = c1.getDamage();
        int excessAttack = dmg1 - hp2;
        int x = hp1 - excessAttack;
        if (x >0) {
            p1.setNewHP(x);
        }
        else{
            std::cout<<"Player is dead! "<<std::endl;
            std::cout<<std::endl;
        }
    }

    void attackCreatureWithSorcery(std::string s){
        for (int i=0;i<play.size();i++){
            if (s == play[i]->getName()){
                if (play[i]->getClassType() == 2){
                    play[i]->setCreatureHP(-2);
                    std::cout<<"2 Damage have been dealt to creature "<<play[i]->getName()<<std::endl;
                    break;
                } else{
                    std::cout<<"That card is not a creature card! "<<std::endl;
                    break;
                }
            }
        }
    }

    void setNewHP(int x){
        playerHP = x;
    }

    void printAvailableEnchantmentCards(){
        for (int i=0;i<play.size();i++){
            if (play[i]->getClassType() == 3){
                std::cout<<play[i]->getName()<<std::endl;
            }
        }
    }

    void printAvailableLandCards(){
        for (int i=0;i<play.size();i++){
            if (play[i]->getClassType() == 2){
                std::cout<<play[i]->getName()<<std::endl;
            }
        }
    }

    void addFirstStrikeAbility(std::string s){
        for (int i=0;i<play.size();i++){
            if(s == play[i]->getName()){
                play[i]->setFirstStrikeAbility(false);
                std::cout<<"First Strike ability of creature "<<play[i]->getName()<<" has been removed! "<<std::endl;
            }
        }
        std::cout<<std::endl;
    }
    void destroyTargetEnchantment(std::string s){
        for (int i=0;i<play.size();i++){
            if (s == play[i]->getName()){
                if (play[i]->getClassType() == 3) {
                    play.erase(play.begin() + i);
                    std::cout << "Enchantment " << play[i]->getName() << " is destroyed! " << std::endl;
                    std::cout << std::endl;
                    break;
                }
            }
        }
    }

    void destroyTargetLand(std::string s){
        for (int i=0;i<play.size();i++){
            if (s == play[i]->getName()){
                if (play[i]->getClassType() == 1) {
                    play.erase(play.begin() + i);
                    std::cout << "Land " << play[i]->getName() << " is destroyed! " << std::endl;
                    std::cout << std::endl;
                    break;
                }
            }
        }
    }

    void destroyTargetCreature(std::string s){
        for (int i=0;i<play.size();i++){
            if (s == play[i]->getName()){
                if (play[i]->getClassType() == 2) {
                    play.erase(play.begin() + i);
                    std::cout << "Creture " << play[i]->getName() << " is destroyed! " << std::endl;
                    std::cout << std::endl;
                    break;
                }
            }
        }
    }

    void dealDamageToCreaureCardsInPlay(){
        for (int i = 0; i <play.size() ; ++i) {
            if (play[i]->getClassType() == 2){
                play[i]->setCreatureHP(-1);
                std::cout<<"One damage have been dealt to creature "<<play[i]->getName()<<std::endl;
                std::cout<<"Creature have "<<play[i]->getHP()<<" HP left! "<<std::endl;
            }
        }
        std::cout<<std::endl;
    }

    void setEnchantmentCard(Card& c){
        std::string s;
        bool x;
        if (c.getName() == "Rage"){
            std::cout<<"Select one creature to add Trample ability "<<std::endl;
            std::cout<<std::endl;
            printCreatureCardsInPlay();
            std::cin>>s;
            x = checkIfInPlayPile(s);
            if (!x){
                while (!x){
                    std::cout<<"Chosen card is not in play pile try again! "<<std::endl;
                    std::cout<<std::endl;
                    std::cin>>s;
                    x = checkIfInPlayPile(s);
                }
            }
            addTrampleAbility(s);
        }
        else if(c.getName() == "HolyWar"){
            for (int i=0;i<play.size();i++){
                if (play[i]->getClassType() == 2){
                    if (play[i]->getCarColor() == "White"){
                        play[i]->setCreatureDamage(1);
                        play[i]->setCreatureHP(1);
                        std::cout<<"1 HP and 1 attack power added to creature "<<play[i]->getName()<<std::endl;
                        std::cout<<std::endl;
                    }
                }
            }
        }else if (c.getName() == "HolyLight"){
            for (int i=0;i<play.size();i++){
                if (play[i]->getClassType() == 2){
                    if (play[i]->getCarColor() == "Black"){
                        play[i]->setCreatureDamage(-1);
                        play[i]->setCreatureHP(-1);
                        std::cout<<"1 HP and 1 attack power removed from creature "<<play[i]->getName()<<std::endl;
                        std::cout<<std::endl;
                    }
                }
            }
        }else if(c.getName() == "UnholyWar"){
            for (int i=0;i<play.size();i++){
                if (play[i]->getClassType() == 2){
                    if (play[i]->getCarColor() == "Black"){
                        play[i]->setCreatureDamage(2);
                        play[i]->setCreatureHP(0);
                        std::cout<<"2 attack power added to creature "<<play[i]->getName()<<std::endl;

                    }
                }
                std::cout<<std::endl;
            }
        }else if(c.getName() == "Restrain"){
            for (int i=0;i<play.size();i++){
                if (play[i]->getClassType() == 2){
                    if (play[i]->getCarColor() == "Green"){
                        play[i]->setTrampleAbility(false);
                        std::cout<<"Creature "<<play[i]->getName()<<" has lost his trample ability! "<<std::endl;
                    }
                }
            }
            std::cout<<std::endl;
        }
        else if(c.getName() == "Slow"){
            std::cout<<"Select one creature to remove First Strike ability "<<std::endl;
            std::cout<<std::endl;
            printCreatureCardsInPlay();
            std::cin>>s;
            x = checkIfInPlayPile(s);
            if (!x){
                while (!x){
                    std::cout<<"Chosen card is not in play pile try again! "<<std::endl;
                    std::cout<<std::endl;
                    std::cin>>s;
                    x = checkIfInPlayPile(s);
                }
            }
            addFirstStrikeAbility(s);
        }
    }

   bool getPlayedLandInFirstRound(){
        return playedLandInFirstRound;
    }

    void setPlayedLandInFirstRound(bool x){
        playedLandInFirstRound = x;
    }

    void deleteManas(){
        currentMana = " ";
    }

    bool hasCreatureCard(){
        bool x = false;
        for (int i=0;i<play.size();i++){
            if (play[i]->getClassType() == 2){
                x = true;
                break;
            }
        }
        return x;
    }

    void printCardsInPlay(){
        for (int i=0;i<play.size();i++){
            std::cout<<play[i]->getName()<<std::endl;
        }
    }

    void eraseMana(){
        if (!currentMana.empty()) {
            currentMana.erase(currentMana.size() - 1);
        }
        printCurrentMana();
    }

    void fromDiscardToPlay(std::string s){
        for (int i=0;i<discard.size();i++){
            if (s == discard[i]->getName()){
                play.push_back(discard[i]);
                discard.erase(discard.begin()+i);
                break;
            }
        }
    }

    void addToDiscardPile(std::string s){
        for (int i=0;i<play.size();i++){
            if(s == play[i]->getName()){
                discard.push_back(play[i]);
                play.erase(play.begin()+i);
                break;
            }
        }
    }
    void printDiscarPileCards(){
        for (int i = 0; i < discard.size(); i++) {
            std::cout << discard[i]->getName() << std::endl;
        }
    }

    bool isDiscardEmpty(){
        if(discard.size() == 0){
            return true;
        }
        else return false;
    }

    bool checkIfInDiscardPile(std::string s){
        bool x = false;
        for (int i=0;i<discard.size();i++){
            if (s == discard[i]->getName()){
                x = true;
                break;
            }
        }
        return x;
    }


    ~Player(){
       /* delete hand;
        delete discard;
        delete play;
        delete deck;*/
    }
};


int main(){
    Player playerA;
    Player playerB;

    std::vector<sorceryCard*> s;
    sorceryCard s1("Disenchant");
    sorceryCard s2("LightningBolt");
    sorceryCard s3("Flood");
    sorceryCard s4("Flood");
    s.push_back(&s1);
    s.push_back(&s2);
    s.push_back(&s3);
    s.push_back(&s4);

    std::vector<creatureCard*> c;
    creatureCard c1("Soldier");
    creatureCard c2("Soldier");
    creatureCard c3("Soldier");
    creatureCard c4("ArmoredPegasus");
    creatureCard c5("ArmoredPegasus");
    creatureCard c6("WhiteKnight");
    creatureCard c7("WhiteKnight");
    creatureCard c8("AngryBear");
    creatureCard c9("Guard");
    creatureCard c10("Werewolf");

    c.push_back(&c1);
    c.push_back(&c2);
    c.push_back(&c3);
    c.push_back(&c4);
    c.push_back(&c5);
    c.push_back(&c6);
    c.push_back(&c7);
    c.push_back(&c8);
    c.push_back(&c9);
    c.push_back(&c10);

    std::vector<enhancementCard*> e;
    enhancementCard e1("HolyWar");
    enhancementCard e2("Rage");
    enhancementCard e3("HolyLight");

    e.push_back(&e1);
    e.push_back(&e2);
    e.push_back(&e3);

    std::vector<landCard*> l;
    landCard l1("Forest");
    landCard l2("Forest");
    landCard l3("Forest");
    landCard l4("Plains");
    landCard l5("Plains");
    landCard l6("Plains");
    landCard l7("Plains");
    landCard l8("Plains");
    landCard l9("Island");

    l.push_back(&l1);
    l.push_back(&l2);
    l.push_back(&l3);
    l.push_back(&l4);
    l.push_back(&l5);
    l.push_back(&l6);
    l.push_back(&l7);
    l.push_back(&l8);
    l.push_back(&l9);

    playerA.addBeginningSorceryCards(s);
    playerA.addBeginningCreatureCards(c);
    playerA.addBeginningEnhancementCards(e);
    playerA.addBeginningLandCards(l);

    //playerB

    std::vector<sorceryCard*> a;
    sorceryCard a1("Terror");
    sorceryCard a2("Terror");
    sorceryCard a3("Reanimate");
    sorceryCard a4("Plague");

    a.push_back(&a1);
    a.push_back(&a2);
    a.push_back(&a3);
    a.push_back(&a4);


    std::vector<creatureCard*> y;
    creatureCard y1("Skeleton");
    creatureCard y2("Skeleton");
    creatureCard y3("Skeleton");
    creatureCard y4("Ghost");
    creatureCard y5("Ghost");
    creatureCard y6("Hobgoblin");
    creatureCard y7("Vampire");
    creatureCard y8("OrcManiac");
    creatureCard y9("BlackKnight");
    creatureCard y10("BlackKnight");

    y.push_back(&y1);
    y.push_back(&y2);
    y.push_back(&y3);
    y.push_back(&y4);
    y.push_back(&y5);
    y.push_back(&y6);
    y.push_back(&y7);
    y.push_back(&y8);
    y.push_back(&y9);
    y.push_back(&y10);

    std::vector<enhancementCard*> z;
    enhancementCard z1("Restrain");
    enhancementCard z2("Slow");
    enhancementCard z3("UnholyWar");

    z.push_back(&z1);
    z.push_back(&z2);
    z.push_back(&z3);

    std::vector<landCard*> w;
    landCard w1("Swamp");
    landCard w2("Swamp");
    landCard w3("Swamp");
    landCard w4("Swamp");
    landCard w5("Swamp");
    landCard w6("Mountain");
    landCard w7("Mountain");
    landCard w8("Mountain");
    landCard w9("Island");

    w.push_back(&w1);
    w.push_back(&w2);
    w.push_back(&w3);
    w.push_back(&w4);
    w.push_back(&w5);
    w.push_back(&w6);
    w.push_back(&w7);
    w.push_back(&w8);
    w.push_back(&w9);

    playerB.addBeginningSorceryCards(a);
    playerB.addBeginningCreatureCards(y);
    playerB.addBeginningEnhancementCards(z);
    playerB.addBeginningLandCards(w);

    playerA.shuffle();
    playerB.shuffle();


    playerA.draw(5);
    playerB.draw(5);


    std::cout<<"playerA have drawn the cards : "<<std::endl;
    playerA.printCards();
    std::cout<<std::endl;

    std::cout<<"playerB have drawn the cards : "<<std::endl;
    playerB.printCards();
    std::cout<<std::endl;



    int numToSend;
    int x;
    std::string card;
    bool checked;
    int whichCard;
    std::string asd;
    int ask;
    int getOut;
    int count = 0;

    while(playerA.getHp() > 0 || playerB.getHp() >0){
        std::cout<<"playerA HP: "<<playerA.getHp()<<std::endl;
        std::cout<<"playerB HP: "<<playerB.getHp()<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Cards in hand for playerA : "<<std::endl;
        playerA.printCards();
        std::cout<<std::endl;

        std::cout<<"Cards In player for playerA : ";
        playerA.printCardsInPlay();
        std::cout<<"Cards In player for playerB : ";
        playerB.printCardsInPlay();
        std::cout<<std::endl;


        std::cout<<"playerA has "<<playerA.getCardNumInHand()<<" cards in hand."<<std::endl;
        if (playerA.getCardNumInDeck() - 1 > 0){
            playerA.draw(1);
            std::cout<<"PlayerA have drawn 1 card! "<<std::endl;
        }else{
            std::cout<<"playerA have lost the game! "<<std::endl;
            break;
        }

        std::cout<<"Available cards for playerA : "<<std::endl;
        std::cout<<std::endl;
        playerA.printCards();
        //untap, start combat
        playerA.setUntapped();
        std::cout<<std::endl;
        std::cout<<"Card playing phase is starting press X to end play phase "<<std::endl;
        playerA.printCards();
        std::cout<<std::endl;
        playerA.printCurrentMana();
        std::cout<<"Enter the card you would like to play: "<<std::endl;
        std::cin>>card;
        while (card != "X") {
            checked = playerA.checkIfInHandPile(card);
            if (!checked) {
                while (!checked) {
                    std::cout << "Chosen card is not in hand pile try again! " << std::endl;
                    std::cout << std::endl;
                    std::cin >> card;
                    checked = playerA.checkIfInHandPile(card);
                }
            }


            playerA.addToPlayPile(card);
            whichCard = playerA.checkCardType(card);
            if (playerA.getPlayedLandInFirstRound() == true && whichCard == 1) {
                while (whichCard == 1) {
                    std::cout << "You already played a land card! Try again: " << std::endl;
                    std::cin >> card;
                    whichCard = playerB.checkCardType(card);
                    playerA.eraseMana();
                }
            }
            playerA.addToPlayPile(card);

            if (whichCard == 1) {
                std::cout << "You cannot play land card in 2nd play phase! " << std::endl;
                std::cout << std::endl;
                playerA.setPlayedLandInFirstRound(true);
            } else if (whichCard == 2) {
                //creature card
                //check which creature card, then check if there are any enchament card then check if there are any defending creature for playerB then attack.
                Card cardToSend;
                cardToSend = playerA.returnCard(card);
                std::cout << "Defending creature for playerB ? press 1 if yes: " << std::endl;
                std::cout << std::endl;
                std::cin >> ask;
                if (ask == 1) {
                    std::cout << "Which creature you want to use? " << std::endl;
                    std::cout << std::endl;
                    playerB.printCreatureCardsInHand();
                    std::cin >> asd;
                    checked = playerB.checkIfInHandPile(asd);
                    if (!checked) {
                        while (!checked) {
                            std::cout << "Chosen card is not in hand pile try again! " << std::endl;
                            std::cout << std::endl;
                            std::cin >> asd;
                            checked = playerB.checkIfInHandPile(asd);
                        }
                    }
                    playerB.addDefendingCreature(asd);
                    Card defender = playerB.returnCard(asd);
                    if (playerA.hasFirstStrikeAbility(cardToSend) || playerA.hasTrampleAbility(cardToSend)) {
                        if (playerA.hasFirstStrikeAbility(cardToSend)) {
                            if (playerB.hasFirstStrikeAbility(defender)) {
                                //normal procedure
                                if (playerA.isCreatureDead(cardToSend) || playerB.isCreatureDead(defender)) {
                                    if (playerB.isCreatureDead(defender)) {
                                        std::cout << "playerB creature is dead! " << std::endl;
                                        std::cout << std::endl;
                                        playerA.attackPlayer(cardToSend, playerB);
                                        std::cout<<"playerB has "<<playerB.getHp()<<" HP left! "<<std::endl;
                                        if (playerB.isPlayerDead()){
                                            std::cout << "playerB is dead!! " << std::endl;
                                            std::cout << "playerA has " << playerA.getHp() << " HP left!" << std::endl;
                                            return 0;
                                        }
                                    } else {
                                        std::cout << "playerA creature is dead! " << std::endl;
                                        std::cout << std::endl;
                                        playerB.attackPlayer(defender, playerA);
                                        std::cout<<"playerA has "<<playerA.getHp()<<" HP left! "<<std::endl;
                                        if (playerA.isPlayerDead()){
                                            std::cout << "playerA is dead!! " << std::endl;
                                            std::cout << "playerB has " << playerB.getHp() << " HP left!" << std::endl;
                                            return 0;
                                        }
                                    }
                                } else {
                                    playerA.attackDefendingCreature(cardToSend, defender);
                                }
                            } else {
                                //first strike ability
                                if (playerB.isCreatureDead(defender)) {
                                    std::cout << "Defending creature of playerB is dead! " << std::endl;
                                    std::cout << std::endl;
                                    playerA.attackPlayer(cardToSend, playerB);
                                    std::cout<<"playerB has "<<playerB.getHp()<<" HP left! "<<std::endl;
                                    if (playerB.isPlayerDead()){
                                        std::cout << "playerB is dead!! " << std::endl;
                                        std::cout << "playerA has " << playerA.getHp() << " HP left!" << std::endl;
                                        return 0;
                                    }
                                } else {
                                    playerA.firstStrikeAttack(cardToSend, defender);
                                }

                            }
                        } else {
                            //hasTrample
                            playerA.trampleAttack(cardToSend, defender, playerB);
                            std::cout<<"playerB has "<<playerB.getHp()<<" HP left! "<<std::endl;
                            if (playerB.isPlayerDead()) {
                                std::cout << "playerB is dead!! " << std::endl;
                                std::cout << "playerA has " << playerA.getHp() << " HP left! " << std::endl;
                                std::cout << std::endl;
                                return 0;
                            }
                        }

                    } else {
                        //playerA creature doesn't have any ability.
                        if (playerB.hasTrampleAbility(defender) || playerB.hasFirstStrikeAbility(defender)) {
                            if (playerB.hasFirstStrikeAbility(defender)) {
                                //first strike ability applied to playerA
                                if (playerA.isCreatureDead(cardToSend)) {
                                    std::cout << "Attacking creature of playerA is dead! " << std::endl;
                                    std::cout << std::endl;
                                    playerB.attackPlayer(defender, playerA);
                                    std::cout<<"playerA has "<<playerA.getHp()<<" HP left!"<<std::endl;
                                } else {
                                    playerB.firstStrikeAttack(defender, cardToSend);
                                }
                            }
                            /* else{
                                 //trample ability applied to playerA
                                 //buraya gerek yok.
                             }*/
                        } else {
                            //normal procedure
                            if (playerA.isCreatureDead(cardToSend) || playerB.isCreatureDead(defender)) {
                                if (playerB.isCreatureDead(defender)) {
                                    std::cout << "playerB creature is dead! " << std::endl;
                                    std::cout << std::endl;
                                    playerA.attackPlayer(cardToSend, playerB);
                                    std::cout<<"playerB has "<<playerB.getHp()<<" HP left! "<<std::endl;
                                } else {
                                    std::cout << "playerA creature is dead! " << std::endl;
                                    std::cout << std::endl;
                                    playerB.attackPlayer(defender, playerA);
                                    std::cout<<"playerA has "<<playerA.getHp()<<" HP left!"<<std::endl;
                                }
                            }
                            else {
                                playerA.attackDefendingCreature(cardToSend, defender);
                            }
                        }
                    }
                } else {
                    //creature vs player
                    playerA.attackPlayer(cardToSend, playerB);
                    std::cout<<"playerB has "<<playerB.getHp()<<" HP left! "<<std::endl;
                    if (playerB.isPlayerDead()) {
                        std::cout << "playerB is dead!! " << std::endl;
                        std::cout << "playerA has " << playerA.getHp() << " HP left!" << std::endl;
                        return 0;
                    }
                }

            } else if (whichCard == 3) {
                //enchantment card
                Card cardToSend2;
                cardToSend2 = playerA.returnCard(card);
                playerA.setEnchantmentCard(cardToSend2);
            } else if (whichCard == 4) {
                //sorcery card
                std::string ret;
                Card cardToSend3;
                cardToSend3 = playerA.returnCard(card);
                if (cardToSend3.getName() == "Disenchant") {
                    std::cout << "Select one enchantment card to destroy: " << std::endl;
                    playerB.printAvailableEnchantmentCards();
                    std::cin >> ret;
                    checked = playerB.checkIfInPlayPile(ret);
                    if (!checked) {
                        while (!checked) {
                            std::cout << "Chosen card is not in play pile try again! " << std::endl;
                            std::cout << std::endl;
                            std::cin >> ret;
                            checked = playerB.checkIfInHandPile(ret);
                        }
                    }
                    playerB.destroyTargetEnchantment(ret);
                } else if (cardToSend3.getName() == "LightningBolt") {
                    int choice;
                    std::cout << "Do you want to attack the player or a creature? 1 for player 2 for creature "
                              << std::endl;
                    std::cin >> choice;
                    while (!(choice == 1 || choice == 2)) {
                        std::cout << "That is not a valid entry please try again! " << std::endl;
                        std::cin >> choice;
                    }
                    if (choice == 1) {
                        playerB.lowerHP(2);
                        std::cout<<"Enemy has "<<playerB.getHp()<<" HP left! "<<std::endl;
                        std::cout<<std::endl;
                        if (playerB.isPlayerDead()){
                            std::cout<<"playerB is dead! "<<std::endl;
                            std::cout<<"playerA has "<<playerA.getHp()<<" HP left! "<<std::endl;
                            return 0;
                        }
                    } else if (choice == 2) {
                        std::cout << "Choose a creature card to attack: " << std::endl;
                        playerB.printCreatureCardsInPlay();
                        std::cin >> ret;
                        checked = playerB.checkIfInPlayPile(ret);
                        if (!checked) {
                            while (!checked) {
                                std::cout << "Chosen card is not in play pile try again! " << std::endl;
                                std::cout << std::endl;
                                std::cin >> ret;
                                checked = playerB.checkIfInHandPile(ret);
                            }
                        }
                        playerB.attackCreatureWithSorcery(ret);
                    }

                } else if (cardToSend3.getName() == "Flood") {
                    std::cout << "Choose a land to destroy: " << std::endl;
                    playerB.printAvailableLandCards();
                    std::cin >> ret;
                    checked = playerB.checkIfInPlayPile(ret);
                    if (!checked) {
                        while (!checked) {
                            std::cout << "Chosen card is not in play pile try again! " << std::endl;
                            std::cout << std::endl;
                            std::cin >> ret;
                            checked = playerB.checkIfInHandPile(ret);
                        }
                    }
                    playerB.destroyTargetLand(ret);
                } else if (cardToSend3.getName() == "Reanimate") {
                    if (playerA.isDiscardEmpty()){
                        std::cout<<"Discard Pile is empty! "<<std::endl;
                    }
                    else{
                        if (playerA.getCardNumInHand() + 1 <= 7 ) {
                            std::string kfe;
                            std::cout << "Discard pile cards are: " << std::endl;
                            playerA.printDiscarPileCards();
                            std::cout << "Select one card to return to your hand: " << std::endl;
                            std::cin >> kfe;
                            checked = playerA.checkIfInDiscardPile(kfe);
                            if (!checked) {
                                while (!checked) {
                                    std::cout << "Chosen card is not in discard pile try again! " << std::endl;
                                    std::cout << std::endl;
                                    std::cin >> kfe;
                                    checked = playerA.checkIfInDiscardPile(kfe);
                                }
                            }
                            playerA.fromDiscardToPlay(kfe);
                        }
                        else{std::cout<<"Your hand pile is already full! You cannot add more cards "<<std::endl;}

                    }
                } else if (cardToSend3.getName() == "Plague") {
                    std::cout << "Dealing one damage to creatures: " << std::endl;
                    playerB.printCreatureCardsInPlay();
                    playerB.dealDamageToCreaureCardsInPlay();
                } else if (cardToSend3.getName() == "Terror") {
                    std::cout << "Choose a creature to destroy: " << std::endl;
                    playerB.printCreatureCardsInPlay();
                    std::cin >> ret;
                    checked = playerB.checkIfInPlayPile(ret);
                    if (!checked) {
                        while (!checked) {
                            std::cout << "Chosen card is not in play pile try again! " << std::endl;
                            std::cout << std::endl;
                            std::cin >> ret;
                            checked = playerB.checkIfInHandPile(ret);
                        }
                    }
                    playerB.destroyTargetCreature(ret);
                }
            }
            std::cout<<"Available cards for playerA : "<<std::endl;
            playerA.printCards();
            std::cout<<"Enter the card you would like to play: "<<std::endl;
            std::cin >> card;

        }
        playerA.addToDiscardPile(card);

        //turn is given to playerB
        std::cout<<"Turn is given to playerB! "<<std::endl;
        //playerA.deleteManas();
        //playerB.deleteManas();
        std::cout<<std::endl;
        std::cout<<"playerA HP: "<<playerA.getHp()<<std::endl;
        std::cout<<"playerB HP: "<<playerB.getHp()<<std::endl;
        std::cout<<std::endl;

        std::cout<<"Cards In player for playerA : ";
        playerA.printCardsInPlay();
        std::cout<<"Cards In player for playerB : ";
        playerB.printCardsInPlay();
        std::cout<<std::endl;


        std::cout<<"playerB has "<<playerB.getCardNumInHand()<<" cards in hand."<<std::endl;
        if (playerB.getCardNumInDeck() - 1 > 0){
            playerB.draw(1);
            std::cout<<"PlayerB have drawn 1 card! "<<std::endl;
        }else{
            std::cout<<"playerB have lost the game! "<<std::endl;
            return 0;
        }


        std::cout<<"Cards in hand for playerB : "<<std::endl;
        std::cout<<std::endl;
        playerB.printCards();
        std::cout<<std::endl;
        playerB.printCurrentMana();
        //untap, start combat
        playerB.setUntapped();
        std::cout<<"Card playing phase is starting press X to end play phase "<<std::endl;
        std::cout<<"Enter the card you would like to play: "<<std::endl;
        std::cin>>card;
        while (card != "X") {
            checked = playerB.checkIfInHandPile(card);
            if (!checked) {
                while (!checked) {
                    std::cout << "Chosen card is not in hand pile try again! " << std::endl;
                    std::cout << std::endl;
                    std::cin >> card;
                    checked = playerB.checkIfInHandPile(card);
                }
            }
            playerB.addToPlayPile(card);
            whichCard = playerB.checkCardType(card);
            if (playerB.getPlayedLandInFirstRound() == true && whichCard == 1) {
                while (whichCard == 1) {
                    std::cout << "You already played a land card! Try again: " << std::endl;
                    std::cin >> card;
                    whichCard = playerB.checkCardType(card);
                    playerB.eraseMana();
                }
            }
            if (whichCard == 1) {
                std::cout << "You cannot play land card in 2nd play phase! " << std::endl;
                std::cout << std::endl;
                playerB.setPlayedLandInFirstRound(true);
            }
            else if (whichCard == 2) {
                //creature card
                //check which creature card, then check if there are any enchament card then check if there are any defending creature for playerB then attack.
                Card cardToSend;
                cardToSend = playerB.returnCard(card);
                std::cout << "Defending creature for playerA ? press 1 if yes: " << std::endl;
                std::cout << std::endl;
                std::cin >> ask;
                if (ask == 1) {
                    std::cout << "Which creature you want to use? " << std::endl;
                    std::cout << std::endl;
                    playerA.printCreatureCardsInHand();
                    std::cin >> asd;
                    checked = playerA.checkIfInHandPile(asd);
                    if (!checked) {
                        while (!checked) {
                            std::cout << "Chosen card is not in hand pile try again! " << std::endl;
                            std::cout << std::endl;
                            std::cin >> asd;
                            checked = playerA.checkIfInHandPile(asd);
                        }
                    }
                    playerA.addDefendingCreature(asd);
                    Card defender = playerA.returnCard(asd);
                    if (playerB.hasFirstStrikeAbility(cardToSend) || playerB.hasTrampleAbility(cardToSend)) {
                        if (playerB.hasFirstStrikeAbility(cardToSend)) {
                            if (playerA.hasFirstStrikeAbility(defender)) {
                                //normal procedure
                                if (playerB.isCreatureDead(cardToSend) || playerA.isCreatureDead(defender)) {
                                    if (playerA.isCreatureDead(defender)) {
                                        std::cout << "playerA creature is dead! " << std::endl;
                                        std::cout << std::endl;
                                        playerB.attackPlayer(cardToSend, playerA);
                                        std::cout<<"playerA has "<<playerA.getHp()<<" HP left!"<<std::endl;
                                        if (playerA.isPlayerDead()){qqqqqqqq
                                            std::cout << "playerA is dead!! " << std::endl;
                                            std::cout << "playerB has " << playerB.getHp() << " HP left!" << std::endl;
                                            return 0;
                                        }
                                    } else {
                                        std::cout << "playerB creature is dead! " << std::endl;
                                        std::cout << std::endl;
                                        playerA.attackPlayer(defender, playerB);
                                        std::cout<<"playerB has "<<playerB.getHp()<<" HP left!"<<std::endl;
                                        if (playerB.isPlayerDead()){
                                            std::cout << "playerB is dead!! " << std::endl;
                                            std::cout << "playerA has " << playerA.getHp() << " HP left!" << std::endl;
                                            return 0;
                                        }
                                    }
                                } else {
                                    playerB.attackDefendingCreature(cardToSend, defender);
                                }
                            } else {
                                //first strike attack
                                if (playerA.isCreatureDead(defender)) {
                                    std::cout << "Defending creature of playerA is dead! " << std::endl;
                                    std::cout << std::endl;
                                    playerB.attackPlayer(cardToSend, playerA);
                                    std::cout<<"playerA has "<<playerA.getHp()<<" HP left!"<<std::endl;
                                    if (playerA.isPlayerDead()){
                                        std::cout << "playerA is dead!! " << std::endl;
                                        std::cout << "playerB has " << playerB.getHp() << " HP left!" << std::endl;
                                        return 0;
                                    }
                                } else {
                                    playerB.firstStrikeAttack(cardToSend, defender);
                                }

                            }
                        } else {
                            //hasTrample
                            playerB.trampleAttack(cardToSend, defender, playerA);
                            if (playerA.isPlayerDead()) {
                                std::cout << "playerA is dead!! " << std::endl;
                                std::cout << "playerB has " << playerB.getHp() << " HP left! " << std::endl;
                                std::cout << std::endl;
                                break;
                            }
                        }

                    } else {
                        //playerB creature doesn't have any ability.
                        if (playerA.hasTrampleAbility(defender) || playerA.hasFirstStrikeAbility(defender)) {
                            if (playerA.hasFirstStrikeAbility(defender)) {
                                //first strike ability applied to playerA
                                if (playerB.isCreatureDead(cardToSend)) {
                                    std::cout << "Attacking creature of playerB is dead! " << std::endl;
                                    std::cout << std::endl;
                                    playerA.attackPlayer(defender, playerB);
                                    std::cout<<"playerB has "<<playerB.getHp()<<" HP left!"<<std::endl;
                                    if (playerB.isPlayerDead()){
                                        std::cout << "playerB is dead!! " << std::endl;
                                        std::cout << "playerA has " << playerA.getHp() << " HP left!" << std::endl;
                                        return 0;
                                    }

                                } else {
                                    playerA.firstStrikeAttack(defender, cardToSend);
                                }
                            }
                            /* else{
                                 //trample ability applied to playerA
                                 //buraya gerek yok.
                             }*/
                        } else {
                            //normal procedure
                            if (playerB.isCreatureDead(cardToSend) || playerA.isCreatureDead(defender)) {
                                if (playerA.isCreatureDead(defender)) {
                                    std::cout << "playerA creature is dead! " << std::endl;
                                    std::cout << std::endl;
                                    playerB.attackPlayer(cardToSend, playerA);
                                    std::cout<<"playerA has "<<playerA.getHp()<<" HP left!"<<std::endl;
                                    if (playerA.isPlayerDead()){
                                        std::cout << "playerA is dead!! " << std::endl;
                                        std::cout << "playerB has " << playerB.getHp() << " HP left!" << std::endl;
                                        return 0;
                                    }
                                } else {
                                    std::cout << "playerB creature is dead! " << std::endl;
                                    std::cout << std::endl;
                                    playerA.attackPlayer(defender, playerB);
                                    std::cout<<"playerB has "<<playerB.getHp()<<" HP left!"<<std::endl;
                                    if (playerB.isPlayerDead()){
                                        std::cout << "playerB is dead!! " << std::endl;
                                        std::cout << "playerA has " << playerA.getHp() << " HP left!" << std::endl;
                                        return 0;
                                    }
                                }
                            }
                            else {
                                playerB.attackDefendingCreature(cardToSend, defender);
                            }
                        }
                    }
                } else {
                    //creature vs player
                    playerB.attackPlayer(cardToSend, playerA);
                    std::cout<<"playerA has "<<playerA.getHp()<<" HP left! "<<std::endl;
                    if (playerA.isPlayerDead()) {
                        std::cout << "playerA is dead!! " << std::endl;
                        std::cout << "playerB has " << playerB.getHp() << " HP left!" << std::endl;
                        return 0;
                    }
                }
            }
            else if (whichCard == 3) {
                //enchantment card
                Card cardToSend2;
                cardToSend2 = playerA.returnCard(card);
                playerB.setEnchantmentCard(cardToSend2);
            }
            else if (whichCard == 4) {
                //sorcery card
                std::string ret;
                Card cardToSend3;
                cardToSend3 = playerB.returnCard(card);
                if (cardToSend3.getName() == "Disenchant") {
                    std::cout << "Select one enchantment card to destroy: " << std::endl;
                    playerA.printAvailableEnchantmentCards();
                    std::cin >> ret;
                    checked = playerA.checkIfInPlayPile(ret);
                    if (!checked) {
                        while (!checked) {
                            std::cout << "Chosen card is not in play pile try again! " << std::endl;
                            std::cout << std::endl;
                            std::cin >> ret;
                            checked = playerA.checkIfInHandPile(ret);
                        }
                    }
                    playerA.destroyTargetEnchantment(ret);
                } else if (cardToSend3.getName() == "LightningBolt") {
                    int choice;
                    std::cout << "Do you want to attack the player or a creature? 1 for player 2 for creature "
                              << std::endl;
                    std::cin >> choice;
                    while (!(choice == 1 || choice == 2)) {
                        std::cout << "That is not a valid entry please try again! " << std::endl;
                        std::cin >> choice;
                    }
                    if (choice == 1) {
                        playerA.lowerHP(2);
                        std::cout<<"Enemy has "<<playerA.getHp()<<" HP left! "<<std::endl;
                        if (playerA.isPlayerDead()){
                            std::cout<<"playerA is dead! "<<std::endl;
                            std::cout<<"playerB has "<<playerB.getHp()<<" HP left! "<<std::endl;
                            return 0;
                        }
                    } else if (choice == 2) {
                        std::cout << "Choose a creature card to attack: " << std::endl;
                        playerA.printCreatureCardsInPlay();
                        std::cin >> ret;
                        checked = playerA.checkIfInPlayPile(ret);
                        if (!checked) {
                            while (!checked) {
                                std::cout << "Chosen card is not in play pile try again! " << std::endl;
                                std::cout << std::endl;
                                std::cin >> ret;
                                checked = playerA.checkIfInHandPile(ret);
                            }
                        }
                        playerA.attackCreatureWithSorcery(ret);
                    }

                } else if (cardToSend3.getName() == "Flood") {
                    std::cout << "Choose a land to destroy: " << std::endl;
                    playerA.printAvailableLandCards();
                    std::cin >> ret;
                    checked = playerA.checkIfInPlayPile(ret);
                    if (!checked) {
                        while (!checked) {
                            std::cout << "Chosen card is not in play pile try again! " << std::endl;
                            std::cout << std::endl;
                            std::cin >> ret;
                            checked = playerA.checkIfInHandPile(ret);
                        }
                    }
                    playerA.destroyTargetLand(ret);
                } else if (cardToSend3.getName() == "Reanimate") {
                    if (playerB.isDiscardEmpty()){
                        std::cout<<"Discard Pile is empty! "<<std::endl;
                    }
                    else{
                        if (playerB.getCardNumInHand() + 1 <= 7 ) {
                            std::string kfe;
                            std::cout << "Discard pile cards are: " << std::endl;
                            playerB.printDiscarPileCards();
                            std::cout << "Select one card to return to your hand: " << std::endl;
                            std::cin >> kfe;
                            checked = playerB.checkIfInDiscardPile(kfe);
                            if (!checked) {
                                while (!checked) {
                                    std::cout << "Chosen card is not in discard pile try again! " << std::endl;
                                    std::cout << std::endl;
                                    std::cin >> kfe;
                                    checked = playerB.checkIfInDiscardPile(kfe);
                                }
                            }
                            playerB.fromDiscardToPlay(kfe);
                        }
                        else{std::cout<<"Your hand pile is already full! You cannot add more cards "<<std::endl;}
                    }

                } else if (cardToSend3.getName() == "Plague") {
                    std::cout << "Dealing one damage to creatures: " << std::endl;
                    playerA.printCreatureCardsInPlay();
                    playerA.dealDamageToCreaureCardsInPlay();
                } else if (cardToSend3.getName() == "Terror") {
                    if (playerA.hasCreatureCard()) {
                        std::cout << "Choose a creature to destroy: " << std::endl;
                        playerA.printCreatureCardsInPlay();
                        std::cin >> ret;
                        checked = playerA.checkIfInPlayPile(ret);
                        if (!checked) {
                            while (!checked) {
                                std::cout << "Chosen card is not in play pile try again! " << std::endl;
                                std::cout << std::endl;
                                std::cin >> ret;
                                checked = playerA.checkIfInHandPile(ret);
                            }
                        }
                        playerA.destroyTargetCreature(ret);
                    }else{
                        std::cout<<"Enemy doesn't have a creature card! "<<std::endl;
                    }
                }
            }
            std::cout<<"Available cards for playerB : "<<std::endl;
            playerB.printCards();
            std::cin >> card;
        }
        playerB.addToDiscardPile(card);
        playerA.setPlayedLandInFirstRound(false);
        playerB.setPlayedLandInFirstRound(false);

        count++;
        std::cout<<"End Of Round "<<count<<std::endl;

    }
    return 0;
}
