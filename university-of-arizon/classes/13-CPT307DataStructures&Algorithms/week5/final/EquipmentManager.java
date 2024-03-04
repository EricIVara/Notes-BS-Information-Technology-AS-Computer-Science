import java.util.*;
public class EquipmentManager {
    public static void sortEquipment(List<Map<String, String>> equipmentList) {
        equipmentList.sort(new Comparator<Map<String, String>>() {
            @Override
            public int compare(Map<String, String> equipment1, Map<String, String> equipment2) {
                return equipment1.get("cost").compareTo(equipment2.get("cost"));
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
}
