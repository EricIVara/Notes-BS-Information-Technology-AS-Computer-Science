package application;

import Toolkit.Histogram;
import javafx.application.*;
import javafx.scene.*;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.*;

public class Main extends Application {
	Pane pane = new Pane();					// Created new pane object
    TextField textField = new TextField();	// Created new text field object
    VBox box = new VBox();					// Created new vBox object
    
    public void start(Stage primaryStage) throws Exception {
        Label lblFilename = new Label("Filename:", textField);	// Created new label
        lblFilename.setContentDisplay(ContentDisplay.LEFT);		// Label name placement 
        textField.setPrefColumnCount(20);						// Set text file size
        Button btView = new Button("Display");					// Created new button named btView
        HBox hBox = new HBox(lblFilename, btView);				// Created new hBox object
        box.getChildren().addAll(pane, hBox);					// takes 2 parameters for vBox
        Scene scene = new Scene(box);							// Created new scene
        primaryStage.setScene(scene);							// Set scene
        btView.setOnAction(e-> {								// Set button layout
            update();
            box.setTranslateY(10);
            primaryStage.sizeToScene();

        });
        primaryStage.show();									// display stage
    }

    private void update() {										// displays histogram
    	/*********ERROR: cannot resolve histogram import*********
    	* Histogram graph = new Histogram(textField.getText()); *
        * pane.getChildren().add(graph);						*
        ***************************ERROR*************************/
    }

    public static void main(String[] args) {
        Application.launch(args);
    }
}