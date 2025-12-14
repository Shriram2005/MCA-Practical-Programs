/* Student Database System - composition used for multiple base classes */

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Student {
    String name;
    String dob;
    String bloodGroup;
    String address;

    public Student(String name, String dob, String bloodGroup, String address) {
        this.name = name;
        this.dob = dob;
        this.bloodGroup = bloodGroup;
        this.address = address;
    }
}

class PhysicalAttributes {
    double height;
    double weight;

    public PhysicalAttributes(double height, double weight) {
        this.height = height;
        this.weight = weight;
    }
}

class InsuranceInfo {
    String policyNumber;

    public InsuranceInfo(String policyNumber) {
        this.policyNumber = policyNumber;
    }
}

class StudentRecord {
    Student student;
    PhysicalAttributes physical;
    InsuranceInfo insurance;
    String telephone;
    String drivingLicense;
    String id; // unique id

    public StudentRecord(String id, Student student, PhysicalAttributes physical, InsuranceInfo insurance, String telephone, String drivingLicense) {
        this.id = id;
        this.student = student;
        this.physical = physical;
        this.insurance = insurance;
        this.telephone = telephone;
        this.drivingLicense = drivingLicense;
    }

    public void display() {
        System.out.println("ID: " + id + " | Name: " + student.name + " | DOB: " + student.dob + " | Blood: " + student.bloodGroup);
        System.out.println("  Address: " + student.address);
        System.out.println("  Height: " + physical.height + " m | Weight: " + physical.weight + " kg");
        System.out.println("  Insurance: " + insurance.policyNumber);
        System.out.println("  Tel: " + telephone + " | DL: " + drivingLicense);
    }
}

public class StudentDatabase {
    static List<StudentRecord> records = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);

    public static void buildSample() {
        Student s1 = new Student("Shriram", "2004-05-10", "O+", "Nashik");
        PhysicalAttributes p1 = new PhysicalAttributes(1.7, 65);
        InsuranceInfo i1 = new InsuranceInfo("POL12345");
        records.add(new StudentRecord("S101", s1, p1, i1, "9876543210", "DL001"));

        Student s2 = new Student("Asha", "2003-03-20", "A+", "Pune");
        records.add(new StudentRecord("S102", s2, new PhysicalAttributes(1.6,55), new InsuranceInfo("POL54321"), "9123456780", "DL002"));
    }

    public static StudentRecord findById(String id) {
        for (StudentRecord r : records) if (r.id.equals(id)) return r;
        return null;
    }

    public static void main(String[] args) {
        boolean running = true;
        while (running) {
            System.out.println("\n1. Build sample master table\n2. Display all records\n3. Insert new record\n4. Delete record\n5. Edit record\n6. Search by ID\n7. Exit");
            System.out.print("Choose: ");
            int ch = sc.nextInt(); sc.nextLine();
            switch (ch) {
                case 1:
                    records.clear();
                    buildSample();
                    System.out.println("Sample table built.");
                    break;
                case 2:
                    for (StudentRecord r : records) r.display();
                    break;
                case 3:
                    System.out.print("Enter ID: "); String id = sc.nextLine();
                    System.out.print("Name: "); String name = sc.nextLine();
                    System.out.print("DOB: "); String dob = sc.nextLine();
                    System.out.print("Blood Group: "); String bg = sc.nextLine();
                    System.out.print("Address: "); String addr = sc.nextLine();
                    System.out.print("Height (m): "); double h = sc.nextDouble(); System.out.print(" Weight (kg): "); double w = sc.nextDouble(); sc.nextLine();
                    System.out.print("Policy No: "); String pol = sc.nextLine();
                    System.out.print("Telephone: "); String tel = sc.nextLine();
                    System.out.print("Driving Licence: "); String dl = sc.nextLine();
                    Student st = new Student(name, dob, bg, addr);
                    StudentRecord nr = new StudentRecord(id, st, new PhysicalAttributes(h, w), new InsuranceInfo(pol), tel, dl);
                    records.add(nr);
                    System.out.println("Record inserted.");
                    break;
                case 4:
                    System.out.print("Enter ID to delete: "); String delId = sc.nextLine();
                    StudentRecord rem = findById(delId);
                    if (rem != null) { records.remove(rem); System.out.println("Deleted."); } else System.out.println("Not found.");
                    break;
                case 5:
                    System.out.print("Enter ID to edit: "); String eid = sc.nextLine();
                    StudentRecord er = findById(eid);
                    if (er == null) { System.out.println("Not found."); break; }
                    System.out.print("New address: "); String naddr = sc.nextLine();
                    er.student.address = naddr;
                    System.out.print("New telephone: "); String ntel = sc.nextLine();
                    er.telephone = ntel;
                    System.out.println("Edited.");
                    break;
                case 6:
                    System.out.print("Enter ID to search: "); String sid = sc.nextLine();
                    StudentRecord fr = findById(sid);
                    if (fr != null) fr.display(); else System.out.println("Not found.");
                    break;
                case 7:
                    running = false; break;
                default:
                    System.out.println("Invalid choice.");
            }
        }
        System.out.println("Exiting Student Database.");
    }
}
