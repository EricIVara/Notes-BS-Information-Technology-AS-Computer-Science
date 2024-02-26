// This class could extend TreeNode to handle specific data or behavior related to car models
public class CarModelNode extends TreeNode<String> {
    private String make;
    private String model;

    public CarModelNode(String make, String model) {
        super(make + " - " + model); // Combining make and model as the data for the TreeNode
        this.make = make;
        this.model = model;
    }

    // Specific getters and setters for make and model, if needed
    public String getMake() {
        return make;
    }

    public void setMake(String make) {
        this.make = make;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }
}
