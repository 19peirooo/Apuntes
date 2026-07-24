import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
      ),
      home: CalculadoraPage(nombreApp: "Calculadora"),
    );
  }
}

class CalculadoraPage extends StatefulWidget {
  final String nombreApp;

  const CalculadoraPage({super.key, required this.nombreApp});

  @override
  State<CalculadoraPage> createState() => _CalculadoraState();
}

class _CalculadoraState extends State<CalculadoraPage> {
  String result = "0";
  String display = "0";
  String? operator = null;
  double? res = null;

  void evaluate() {

    if (operator == null) {
      ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text("Falta Operador"))
      );
      return;
    }

    int opIndex = display.indexOf(operator!, 1);

    if (opIndex == -1) {
      ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text("Operacion invalida"))
      );
      return;
    }

    String left = display.substring(0, opIndex);
    String right = display.substring(opIndex + 1);

    double? num1 = double.tryParse(left);
    double? num2 = double.tryParse(right);

    if (num1 == null || num2 == null) {
      ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text("Datos Invalidos"))
      );
      return;
    }

    switch(operator) {
      case '+':
        res = num1 + num2;
        break;

      case '-':
        res = num1 - num2;
        break;

      case 'X':
        res = num1 * num2;
        break;

      case '/':
        if (num2 == 0) {
          ScaffoldMessenger.of(context).showSnackBar(
              SnackBar(content: Text("Division Entre Cero"))
          );
          return;
        }
        res = num1 / num2;
        break;

      case '%':
        if (num2 == 0) {
          ScaffoldMessenger.of(context).showSnackBar(
              SnackBar(content: Text("Division Entre Cero"))
          );
          return;
        }
        res = num1 % num2;
        break;
    }
  }

  void onButtonPressed(String val) {
    setState(() {
      if (val == "AC") {
        display="0";
        result="0";
        operator=null;
        res = null;
      }
      else if (val == "C") {
        if (display.isNotEmpty && display != "0") {
          display = display.substring(0, display.length - 1);

          if (display.isEmpty) {
            display = "0";
          }
        }
      }
      else if (val == "+/-") {

        if (display == "0") return;

        if (operator != null) {

          int opIndex = display.lastIndexOf(operator!);

          String firstPart = display.substring(0, opIndex + 1);
          String secondPart = display.substring(opIndex + 1);

          if (secondPart.startsWith("-")) {
            secondPart = secondPart.substring(1);
          } else {
            secondPart = "-$secondPart";
          }

          display = firstPart + secondPart;

        } else {

          if (display.startsWith("-")) {
            display = display.substring(1);
          } else {
            display = "-$display";
          }
        }
      }
      else if (['+','-','X','/','%'].contains(val)) {

        if (operator != null) {

          evaluate();

          if (res != null) {
            result = display;
            display = res.toString();
          }
        }

        display += val;
        operator = val;
      }
      else if (val == '=') {

        evaluate();
        if (res != null) {
          String temp = display;
          result = temp;
          display = res.toString();
          operator = null;
        }

      }
      else {
        if (display == "0") {
          display = val;
        } else {
          display += val;
        }
      }
    });
  }

  Widget makeButton(String text, Color col) {
    return Expanded(
      child: Padding(
        padding: const EdgeInsets.all(1.0),
        child: ElevatedButton(
          style: ElevatedButton.styleFrom(
            shape: const CircleBorder(),
            padding: const EdgeInsets.all(24),
            backgroundColor: col,
          ),
          onPressed: () => onButtonPressed(text),
          child: Text(
            text,
            style: const TextStyle(fontSize: 24, color: Colors.white),
          ),
        ),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black,
      body: Center(
        child: Container(
          padding: EdgeInsets.all(24),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            crossAxisAlignment: CrossAxisAlignment.end,
            children: [
              Text(
                result,
                style: TextStyle(fontSize: 30, color: Colors.grey),
              ),
              Text(display, style: TextStyle(fontSize: 60, color: Colors.white)),
              Padding(padding: EdgeInsets.only(top: 24)),
              Container(
                child: Column(
                  children: [
                    Row(
                      children: [
                        makeButton("C", Colors.white30),
                        makeButton("AC", Colors.white30),
                        makeButton("%", Colors.white30),
                        makeButton("/", Colors.orange),
                      ],
                    ),
                    Row(
                      children: [
                        makeButton("7", Colors.grey[800]!),
                        makeButton("8", Colors.grey[800]!),
                        makeButton("9", Colors.grey[800]!),
                        makeButton("X", Colors.orange),
                      ],
                    ),
                    Row(
                      children: [
                        makeButton("4", Colors.grey[800]!),
                        makeButton("5", Colors.grey[800]!),
                        makeButton("6", Colors.grey[800]!),
                        makeButton("-", Colors.orange),
                      ],
                    ),
                    Row(
                      children: [
                        makeButton("1", Colors.grey[800]!),
                        makeButton("2", Colors.grey[800]!),
                        makeButton("3", Colors.grey[800]!),
                        makeButton("+", Colors.orange),
                      ],
                    ),
                    Row(
                      children: [
                        makeButton("+/-", Colors.grey[800]!),
                        makeButton("0", Colors.grey[800]!),
                        makeButton(".", Colors.grey[800]!),
                        makeButton("=", Colors.orange),
                      ],
                    ),
                  ],
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
