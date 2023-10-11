/*
    HR ของบริษัทเน็ตเวิร์คทำการกรอกข้อมูลพนักงานลงไปในระบบคำนวณฐานภาษีเพื่อเตรียมส่งยอดภาษีสู่ฝ่ายบัญชี โดยจะหักภาษี ณ ที่จ่าย 7% ของเงินเดือนที่ได้ ให้คุณคำนวณภาษีพนักงานทั้งหมดที่บริษัทของคุณต้องชำระภายในปีนี้ (กรอกเลข -1 ถือเป็นการสิ้นสุดการกรอก และทำการสรุปผลภาษีที่ต้องชำระภายในปีนี้) และสร้างฟังก์ชันที่ระบุคนที่ต้องชำระภาษีเยอะที่สุดในบริษัทมาแสดงในผลสรุปยอดของบริษัทด้วย

    Test case:
        Employee 1's Name : 
            Omar
        Sarary (Bath/Month) : 
            12750
        Employee 2's Name : 
            Alice
        Sarary (Bath/Month) : 
            15900
        Employee 3's Name : 
            Max
        Sarary (Bath/Month) : 
            19860
        Employee 4's Name : 
            -1
    Output:
        All salary per month: 48,510.00 Bath
        All salary per year: 582,120.00 Bath
        Tax (7% per year) : 40,748.40 Bath
        Most tax in company : Max (16,682.40 Bath per year)

    Test case:
        Employee 1's Name : 
            John
        Sarary (Bath/Month) : 
            15780
        Employee 2's Name : 
            Oven
        Sarary (Bath/Month) : 
            16890
        Employee 3's Name : 
            May
        Sarary (Bath/Month) : 
            17870
        Employee 4's Name : 
            Bill
        Sarary (Bath/Month) : 
            22100
        Employee 5's Name : 
            -1
    Output:
        All salary per month: 72,640.00 Bath
        All salary per year: 871,680.00 Bath
        Tax (7% per year) : 61,017.60 Bath
        Most tax in company : Bill (18,564.00 Bath per year)
*/

#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    float salary;
    float tax;
};

int main() {
    struct Employee employees[100];
    char name[50];
    float salary;
    int count = 0;

    // Input employee information
    while (1) {
        printf("Employee %d's Name :\n", count + 1);
        scanf("%s", name);

        if (strcmp(name, "-1") == 0) {
            break;
        }

        strcpy(employees[count].name, name);

        printf("Salary (Bath/Month) :\n");
        scanf("%f", &salary);
        employees[count].salary = salary;

        count++;
    }

    // Calculate total salary and tax
    float totalSalaryPerMonth = 0;
    for (int i = 0; i < count; i++) {
        totalSalaryPerMonth += employees[i].salary;
    }

    float totalSalaryPerYear = totalSalaryPerMonth * 12;
    float totalTax = totalSalaryPerYear * 0.07;

    // Find the employee with the highest tax
    int maxTaxIndex = 0;
    float maxTax = employees[0].salary * 12 * 0.07;
    for (int i = 1; i < count; i++) {
        float tax = employees[i].salary * 12 * 0.07;
        if (tax > maxTax) {
            maxTax = tax;
            maxTaxIndex = i;
        }
    }

    // Output results
    printf("All salary per month: %.2f Bath\n", totalSalaryPerMonth);
    printf("All salary per year: %.2f Bath\n", totalSalaryPerYear);
    printf("Tax (7%% per year) : %.2f Bath\n", totalTax);
    printf("Most tax in company : %s (%.2f Bath per year)\n", employees[maxTaxIndex].name, maxTax);

    return 0;
}
