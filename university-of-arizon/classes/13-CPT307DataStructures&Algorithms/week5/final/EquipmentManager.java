import java.util.*;
public class EquipmentManager {
    public static void sortEquipment(List<Map<String, String>> equipmentList) {
        equipmentList.sort(new Comparator<Map<String, String>>() {
            @Override
            public int compare(Map<String, String> equipment1, Map<String, String> equipment2) {
                return equipment2.get("gain").compareTo(equipment1.get("gain"));
            }
        });
    }
    public static Map<String, String> searchEquipment(List<Map<String, String>> equipmentList, String brandName) {
        for(Map<String, String> equipment : equipmentList) {
            if(equipment.get("brandName").equals(brandName)) {
                return equipment;
            }
        }
        return null;
    }

    public static void printSortedEquipment(List<Map<String, String>> equipmentList) {
        System.out.println("Here is the list of equipment in order from most gain to least gain:");
        for (Map<String, String> equipment : equipmentList) {
            System.out.println("Brand Name: " + equipment.get("brandName") + ", Gain: " + equipment.get("gain") + ", Cost: " + equipment.get("cost"));
        }
    }
}