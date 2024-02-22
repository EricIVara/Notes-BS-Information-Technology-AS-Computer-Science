package application;

/*import ToolKit.Histogram;*/
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ContentDisplay;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Program5 extends Application {

    Pane pane = new Pane();
    TextField textField = new TextField();
    VBox box = new VBox();
    @Override
    public void start(Stage primaryStage) throws Exception {

        Label lblFilename = new Label("Filename:", textField);
        lblFilename.setContentDisplay(ContentDisplay.RIGHT);
        textField.setPrefColumnCount(20);
        Button btView = new Button("View");

        HBox hBox = new HBox(lblFilename, btView);

        box.getChildren().addAll(pane, hBox);
        Scene scene = new Scene(box);
        primaryStage.setScene(scene);
        btView.setOnAction(e-> {
            update();
            box.setTranslateY(10);
            primaryStage.sizeToScene();

        });
        primaryStage.show();
    }

    private void update() {
        Histogram graph = new Histogram(textField.getText());
        pane.getChildren().add(graph);
    }


    public static void main(String[] args) {
        Application.launch(args);
    }
}