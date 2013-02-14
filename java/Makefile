
JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	pawn/Pawn.java \
	pawn/BlackPawn.java \
	pawn/WhitePawn.java \
	field/Field.java \
	gameboard/Gameboard.java \
	history/History.java \
	playState/PlayState.java \
	game/Game.java \
	Main.java 

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class