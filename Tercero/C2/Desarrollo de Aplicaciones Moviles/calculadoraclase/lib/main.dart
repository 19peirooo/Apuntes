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
        colorScheme: .fromSeed(seedColor: Colors.deepPurple),
      ),
      home: CalculadoraPage(nombreAPP: "Calculadora UTAD"),
    );
  }
}

class CalculadoraPage extends StatefulWidget {
  final String nombreAPP;

  const CalculadoraPage({
    super.key,
    required this.nombreAPP,
  }); //No obligatorio pero recomendable

  @override
  State<CalculadoraPage> createState() => _CalculadoraState();
}

class _CalculadoraState extends State<CalculadoraPage> {
  int resultado = 0;

  TextEditingController editOP1 = new TextEditingController();
  TextEditingController editOP2 = new TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text(widget.nombreAPP)),
      body: Container(
        padding: EdgeInsets.all(24),
        child: Center(
          child: Column(
            //mainAxisAlignment: MainAxisAlignment.center, //Centrado en eje principal
            //crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              const Text("Calculadora APP"),
              const Padding(padding: EdgeInsets.only(top: 24)),
              const Text("Por favor introduce los datos"),
              const Padding(padding: EdgeInsets.only(top: 24)),
              Container(
                padding: EdgeInsets.only(left: 128, right: 128),
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Expanded(
                      child: TextField(
                        controller: editOP1,
                        decoration: const InputDecoration(
                          border: OutlineInputBorder(),
                          label: Text("Introduce Operando 1"),
                        ),
                      ),
                    ),
                    const Padding(padding: EdgeInsets.only(left: 48)),
                    Expanded(
                      child: TextField(
                        controller: editOP2,
                        decoration: const InputDecoration(
                          border: OutlineInputBorder(),
                          label: Text("Introduce Operando 2"),
                        ),
                      ),
                    )
                  ],
                ),
              ),
              const Padding(padding: EdgeInsets.only(top: 24)),
              Text("El resultado de la suma es $resultado")
            ],
          ),
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          //capturar los elementos de los textfield
          int? op1 = int.tryParse(editOP1.text);
          int? op2 = int.tryParse(editOP2.text);

          if (op1 != null && op2 != null) {
            setState(() {
              resultado = op1 + op2;
            });
          } else {
            ScaffoldMessenger.of(context).showSnackBar(SnackBar(content: Text("Datos Invalidos")));
          }
        }, //Lo que ocurre cuando lo pulsas
        child: Text("Calcular"), //Contenido de boton
      ),
    );
  }
}
