package application;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.HBox;
import javafx.geometry.Insets;
import java.util.ArrayList;

public class Exercise_14_03 extends Application {
	public void start(Stage primaryStage) {
		// declared a list of cards  named cards
		ArrayList<Integer> cards = getCards();
		// declared a new HBox pane named pane
		HBox pane = new HBox(5);
		// specified view
		pane.setPadding(new Insets(5, 5, 5, 5));

		// used a for loop to add nodes to the pane
		for (int i = 0; i < 3; i++) {
			pane.getChildren().add(new ImageView(new Image("image/card/" +
				cards.get(i) + ".png")));
		}

		// declared a new scene while placing it on the stage
		Scene scene = new Scene(pane);
		// Set the title name equal to the class name
		primaryStage.setTitle("Exercise_14_03");
		// put the scene on the stage
		primaryStage.setScene(scene);
		// shows the stage
		primaryStage.show();
	}

	// returns numbers between 1 and 52 while placing them in random order
	private ArrayList<Integer> getCards() {
		ArrayList<Integer> cards = new ArrayList<>();
		for (int i = 0; i < 52; i++) {
			cards.add(i + 1);
		}
		java.util.Collections.shuffle(cards);
		return cards;
	}
}