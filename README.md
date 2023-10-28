# GateBarrier_CarParkSystem
Physical Computing Year 2's Project

## ที่มาและจุดประสงค์

	เนื่องจากในปัจจุบัน รถยนต์เป็นหนึ่งในยานพาหนะยอดนิยมในการเดินทางขนส่ง และเมื่อจำนวนรถยนต์เยอะขึ้น อาคาร/สถานที่สำหรับการจอดรถยนต์ที่มีความปลอดภัยย่อมมีความสำคัญมากขึ้น ทางผู้จัดทำจึงอยากศึกษาเทคโนโลยีที่ใช้ในการตรวจจับ, วัดระยะห่าง และสัญญาณเตือนของรถยนต์ รวมถึงระบบการยกไม้กั้นของอาคารจอดรถ โดยทางผู้จัดทำได้จำลอง ระบบตรวจจับ, วัดระยะห่าง ด้วย Ultra Sonic และสัญญาณเตือนของรถยนต์ ด้วยลำโพง Buzzer และมีการเพิ่มลูกเล่นด้วยการใช้ LED ในการแสดงผลระยะห่างแบบคร่าวๆ


## การทำงานของวงจร

	Ultrasonic จะทำการตรวจสอบระยะห่าง และส่งข้อมูลให้แก่ Arduino uno เพื่อนำไปเข้าเงื่อนไขในการทำงานของ Servo, LED และ Buzzer ต่อไป โดยมีหลักการทำงานดังนี้

เมื่อมีวัตถุอยู่ในระยะตั้งแต่ 30 ซม. ขึ้นไป แสดงแสงไฟสีเขียว 1 หลอด และ Servo ขยับ 0 องศา
เมื่อมีวัตถุอยู่ในระยะตั้งแต่ 10-30 ซม.แสดงแสงไฟสีฟ้า 2 หลอด และ Servo ขยับ 45 องศา
เมื่อมีวัตถุอยู่ในระยะน้อยกว่า 10 ซม. แสดงแสงไฟสีแดง 3 หลอด และ Servo ขยับ 90 องศา
	
	โดยในแต่ละระยะ Buzzer จะส่งเสียงร้องในย่านความถี่ที่แตกต่างกัน


## ชิ้นงานในส่วน Hardware
	
- RGB LED
- HC-SR04
- Micro Servo 9g
- Buzzer Module Low Level Trigger
- Arduino uno

Link สาธิตการทำงาน : https://youtu.be/PwEJIAvrumU
