# STM32F401 Waveform Generator (AWG)

## 1. Panoramica del Progetto
Questo progetto implementa un **Generatore Arbitrario di Forme d'Onda (AWG)** utilizzando la scheda di sviluppo basata sul microcontrollore **STM32F401**.

Il principio di funzionamento si basa sulla generazione di un segnale **PWM (Pulse Width Modulation)** a *duty cycle* variabile. Modificando dinamicamente il duty cycle nel tempo via software, viene fatto variare il valore medio della tensione in uscita dal pin del microcontrollore. 

Per ottenere la forma d'onda analogica finale, il segnale PWM digitale viene fatto passare attraverso un **filtro passa-basso** hardware esterno (circuito RC). Questo filtro ha il compito fondamentale di isolare la componente media del segnale, eliminando le alte frequenze di commutazione del PWM. Collegando l'uscita del filtro a un oscilloscopio, è possibile visualizzare la forma d'onda generata in modo continuo.

---

## 2. Strumenti e Framework
Per lo sviluppo e il collaudo di questo progetto sono state utilizzate le seguenti tecnologie:

* **Libreria CMSIS (Cortex-Microcontroller Software Interface Standard):** Un framework standard fornito da ARM che permette di programmare a basso livello ("bare-metal"). Tramite CMSIS è possibile interagire direttamente con i registri e i singoli bit del microcontrollore, garantendo la massima efficienza e un controllo preciso sulle periferiche hardware necessarie (come i Timer per la generazione del PWM).
* **STM32CubeIDE:** L'ambiente di sviluppo integrato (IDE) ufficiale basato su Eclipse. Offre un ambiente completo per la scrittura del codice e dispone di potenti funzionalità di **in-circuit debugging**, permettendo di eseguire il codice passo-passo, ispezionare lo stato dei registri in tempo reale e testare il comportamento del firmware prima del rilascio.

---

## 3. Istruzioni per l'Esecuzione

### Prerequisiti Importanti
Per poter compilare correttamente il progetto, è **strettamente necessario** includere la libreria **CMSIS** specifica per la famiglia STM32F4xx nei file sorgenti. Assicurati che i percorsi di inclusione (*Include paths*) siano configurati correttamente all'interno delle proprietà del progetto nel tuo IDE.

### Come eseguire il codice sulla scheda target

1.  **Clona la repository** sul tuo computer locale:
    ```bash
    git clone [https://github.com/tuo-nome-utente/STM32F401-Waveform-Generator.git](https://github.com/tuo-nome-utente/STM32F401-Waveform-Generator.git)
    ```
2.  **Importa il progetto:** Apri STM32CubeIDE, naviga in `File > Import... > General > Existing Projects into Workspace` e seleziona la cartella del progetto che hai appena scaricato.
3.  **Configurazione Hardware:**
    * Collega la tua board STM32F401 al computer tramite il cavo USB.
    * Collega l'ingresso del circuito filtro passa-basso al pin configurato per l'uscita del segnale PWM.
    * Collega la sonda di un oscilloscopio all'uscita analogica del filtro.
4.  **Compilazione (Build):**
    * Clicca sul pulsante **Build** (
