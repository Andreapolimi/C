/*******************************************************************
 
 Timemachine.c

Il Dottor Emmett Brown di "Ritorno al Futuro" ha bisogno del vostro aiuto per sviluppare il software del “contachilometri temporale” per la sua DeLorean.
Il programma riceve in input la data di partenza e la data di destinazione. Successivamente calcola e stampa a video la distanza tra le due date in anni, mesi, giorni, ore e minuti.
Requisiti:
•	le date vanno acquisite direttamente in formato DD-MM-YYYY hh:mm
•	va verificata la validità delle date inserite: se almeno una delle date non è valida, allora il programma stampa a video un messaggio di errore e termina l’esecuzione
•	ipotizziamo che la DeLorean possa viaggiare dal 1 gennaio 1888 al 31 dicembre 2100
•	le date non devono essere necessariamente inserite in ordine cronologico, in quanto la DeLorean può viaggiare avanti e indietro nel tempo
•	il programma deve tenere conto degli anni bisestili e del numero differente di giorni presenti in ciascun mese dell'anno
•	non è richiesta l'implementazione del flusso canalizzatore


 * Ispirato al film "Back To The Future" e:
 * https://overiq.com/c-examples/c-program-to-calculate-the-difference-of-two-dates-in-years-months-and-days/
 * https://www.programiz.com/c-programming/examples/time-structure
 * https://overiq.com/c-examples/c-program-to-print-the-earlier-of-the-two-dates/
 *******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int day1, mon1, year1, hour1, minute1,
    day2, mon2, year2, hour2, minute2;

    int temp_day, temp_mon, temp_year, temp_hour, temp_minute, scambio = 0;

    int partial_time1, partial_time2, partial_time_diff, partial_day, partial_hour, partial_minute;

    int day_diff, mon_diff, year_diff, hour_diff, minute_diff;

    printf("Inserisci data e ora di partenza della DeLorean (DD-MM-YYYY hh:mm): ");
    scanf("%d-%d-%d %d:%d", & day1, & mon1, & year1, & hour1, & minute1);

    printf("Inserisci data e ora di destinazione della DeLorean (DD-MM-YYYY hh:mm): ");
    scanf("%d-%d-%d %d:%d", & day2, & mon2, & year2, & hour2, & minute2);

    // verifico che le date inserite siano effettivamente valide e nel caso lo segnalo al conducente della DeLorean
    // parto supponendo che la data sia valida a prescindere e utilizzando un indice per eseguire il ciclo al massimo due volte

    int idx_date = 0, is_valid = 1;
    int is_leap = 0;
    int year, mon, day, hour, minute;

    while (is_valid == 1 && idx_date < 2) {

        is_leap = 0;

        if (idx_date == 0) {
            year = year1;
            mon = mon1;
            day = day1;
            hour = hour1;
            minute = minute1;
        } else {
            year = year2;
            mon = mon2;
            day = day2;
            hour = hour2;
            minute = minute2;
        }

        if (year >= 1888 && year <= 2100) {
            //  controlla se l'anno è bisestile
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                is_leap = 1;

            // controlla se mon è compreso tra 1 e 12
            if (mon >= 1 && mon <= 12) {
                if (mon == 2) {
                    // controlla i giorni di febbraio
                    if (is_leap && day == 29)
                        is_valid = 1;
                    else if (day > 28)
                        is_valid = 0;
                } else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) {
                    // controlla i giorni di aprile, giugno, settembre e novembre
                    if (day > 30)
                        is_valid = 0;
                } else if (day > 31) {
                    // controlla i giorni nel resto dei mesi,
                    // cioè gennaio, marzo, maggio, luglio, agosto, ottobre, dicembre.
                    is_valid = 0;
                }
            } else {
                is_valid = 0;
            }
        } else {
            is_valid = 0;
        }

        // controllo validità orario

        if (hour < 0 || hour > 23 || minute < 0 || minute > 59)
            is_valid = 0;

        if (is_valid == 0 && idx_date == 0) {
            printf("Ehi, McFly! La data di partenza non è valida!\n");
            exit(0);
        }

        if (is_valid == 0 && idx_date == 1) {
            printf("Ehi, McFly! la data di destinazione non è valida!\n");
            exit(0);
        }

        idx_date++;
    }

    // se le date non sono inserite in ordine cronologico le scambio tra loro,
    // la distanza tra le due non cambia, ma l'algoritmo necessita di due date in ordine cronologico

    if (year1 > year2) {
        scambio = 1;
    } else if (year1 == year2) {
        if (mon1 == mon2) {
            if (day1 == day2) {
                if (hour1 == hour2) {
                    if (minute1 > minute2) {
                        scambio = 1;
                    }
                } else if (hour1 > hour2) {
                    scambio = 1;
                }
            } else if (day1 > day2) {
                scambio = 1;
            }
        } else if (mon1 > mon2) {
            scambio = 1;
        }
    }

    if (scambio == 1) {
        temp_day = day1;
        temp_mon = mon1;
        temp_year = year1;
        temp_hour = hour1;
        temp_minute = minute1;

        day1 = day2;
        mon1 = mon2;
        year1 = year2;
        hour1 = hour2;
        minute1 = minute2;

        day2 = temp_day;
        mon2 = temp_mon;
        year2 = temp_year;
        hour2 = temp_hour;
        minute2 = temp_minute;
    }

    // calcolo la distanza tra le date     

    if (day2 < day1) {
        // determino il numero di giorni trascorsi dall'inizio dell'anno di destinazione
        if (mon2 == 3) {
            // prendo giorni in prestito da febbraio:
            // controllo se l'anno di destinazione è bisestile
            // e in base a quello prendo in prestito 28 o 29 giorni
            if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0))
                day2 += 29;
            else
                day2 += 28;
        } else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12) {
            // prendo giorni in prestito dai mesi con 30 giorni
            day2 += 30;
        } else {
            // prendo giorni in prestito dai mesi con 31 giorni
            day2 += 31;
        }

        mon2 = mon2 - 1;
    }

    if (mon2 < mon1) {
        mon2 += 12;
        year2 -= 1;
    }

    // quanto sopra calcola la differenza tra due date supponendo che l'orario di partenza e arrivo sia lo stesso
    // ipotizzandolo pari alle 0:00

    // se le date di arrivo e partenza SONO uguali occorre calcolare in secondi:
    // - il tempo trascorso dall'orario di partenza alla fine del giorno di partenza
    // - il tempo trascorso dall'inizio del giorno di arrivo fino all'orario di arrivo
    // questi due contributi vanno sottratti tra di loro e convertiti in ore e minuti.
    //
    // se le date di arrivo e partenza NON sono uguali occorre calcolare in secondi:
    // - il tempo trascorso dall'orario di partenza alla fine del giorno di partenza
    // - il tempo trascorso dall'inizio del giorno di arrivo fino all'orario di arrivo
    // questi due contributi vanno poi sommati e convertiti in giorni, ore e minuti.
    //
    // il totale dei giorni (che può essere pari a 0 o 1) va poi usato come correttivo per i giorni calcolati in precedenza.

    // calcolo in secondi il tempo trascorso dall'orario di partenza alla fine del giorno di partenza
    partial_time1 = (24 * 60 * 60) - (hour1 * 60 * 60 + minute1 * 60);

    if (day1 == day2 && mon1 == mon2 && year1 == year2) {
        // calcolo in secondi il tempo trascorso dall'orario di arrivo alla fine del giorno di arrivo
        partial_time2 = (24 * 60 * 60) - (hour2 * 60 * 60 + minute2 * 60);
        partial_time_diff = abs(partial_time1 - partial_time2);
    } else {
        // calcolo in secondi il tempo trascorso dall'inizio del giorno di arrivo fino all'orario di arrivo
        partial_time2 = hour2 * 60 * 60 + minute2 * 60;
        partial_time_diff = partial_time1 + partial_time2;
    }

    // converto in giorni, ore e minuti

    partial_day = partial_time_diff / (60 * 60 * 24);
    partial_time_diff -= partial_day * (60 * 60 * 24);
    partial_hour = partial_time_diff / (60 * 60);
    partial_time_diff -= partial_hour * (60 * 60);
    partial_minute = partial_time_diff / 60;

    // non è necessario calcolare la differenza della data come valore assoluto,
    // perché nel caso abbiamo già scambiato le date tra loro prima del calcolo

    day_diff = day2 - day1;
    mon_diff = mon2 - mon1;
    year_diff = year2 - year1;

    // applico il correttivo per i giorni
    if (partial_day == 0 && day_diff > 0)
        day_diff--;

    minute_diff = partial_minute;
    hour_diff = partial_hour;

    printf("Grande Giove! Hai viaggiato nel tempo per %d anni %d mesi %d giorni %d ore e %d minuti!", year_diff, mon_diff, day_diff, hour_diff, minute_diff);

    return 0;
}