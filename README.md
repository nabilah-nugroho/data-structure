# Queue (Antrian) - Struktur Data

## Daftar Isi
1. [Pengertian Queue](#pengertian-queue)
2. [Konsep Dasar](#konsep-dasar)
3. [Operasi Dasar](#operasi-dasar)
4. [Jenis-Jenis Queue](#jenis-jenis-queue)
5. [Implementasi](#implementasi)
6. [Implementasi di File Ini](#implementasi-di-file-ini)

---

## Pengertian Queue

**Queue** adalah struktur data yang mengikuti prinsip **FIFO (First In First Out)**, artinya elemen yang pertama masuk akan menjadi yang pertama keluar. Queue dapat dibayangkan seperti antrian di kasir atau di halte bus, dimana orang pertama yang datang akan dilayani terlebih dahulu.

---

## Konsep Dasar

### Pointer FIFO Queue
- **`front` (depan)**: Menunjuk ke elemen pertama (yang akan dikeluarkan)
- **`rear` (belakang)**: Menunjuk ke elemen terakhir (tempat elemen baru ditambahkan)

### Keadaan Queue
- **Kosong**: `front == -1` dan `rear == -1`
- **Penuh**: `rear == ukuran_array - 1`

---

## Operasi Dasar

### 1. **Enqueue (Menambah Nilai)**
Operasi menambahkan elemen ke belakang (rear) queue.

**Langkah-langkah:**
- Periksa apakah queue penuh (jika array statis). Jika penuh, tampilkan pesan error
- Jika queue kosong, set `front = rear = 0`
- Jika tidak kosong, tambahkan elemen di posisi `rear + 1`
- Perbarui nilai `rear` ke posisi baru
- Masukkan data baru

**Mengapa perlu `rear`?** Untuk mengetahui posisi belakang queue agar bisa menambah elemen baru tanpa menimpa data lama.

### 2. **Dequeue (Menghapus Nilai)**
Operasi menghapus elemen dari depan (front) queue.

**Langkah-langkah:**
- Periksa apakah queue kosong. Jika kosong, tampilkan pesan error (*underflow*)
- Ambil elemen di posisi `front`
- Geser semua elemen ke depan (kiri) satu posisi
- Perbarui nilai `rear` (kurangi 1)
- Jika queue menjadi kosong setelah penghapusan, set `front = rear = -1`

**Problem Queue Linier:** Elemen yang dihapus tidak bisa diisi ulang karena array sudah penuh di belakang.

### 3. **Peek**
Operasi melihat elemen di depan tanpa menghapusnya.

```cpp
if(!isEmpty()) {
    return data[first];
}
```

### 4. **isEmpty()**
Memeriksa apakah queue kosong.

```cpp
if (front == -1) return true; // Queue kosong
```

### 5. **isFull()**
Memeriksa apakah queue penuh (hanya untuk array statis).

```cpp
if (rear == max - 1) return true; // Queue penuh
```

---

## Jenis-Jenis Queue

### 1. **Linear Queue (Queue Linier)**
- Elemen dimasukkan dari belakang (rear), dihapus dari depan (front)
- **Masalah:** Pemborosan memory. Setelah dequeue, ruang di depan tidak bisa digunakan lagi
- **Solusi:** Circular queue atau menggeser elemen ke depan saat dequeue

### 2. **Circular Queue (Queue Melingkar)**
- Elemen disusun secara melingkar, rear dan front bisa saling bertemu
- Efisiensi penggunaan memory lebih baik
- Rumus: `(rear + 1) % ukuran_array`
- **Keuntungan:** Menghindari pemborosan memory
- **Kasus:** Manajemen buffer, scheduler CPU

### 3. **Double Ended Queue (Deque)**
- Perpaduan karakteristik queue dan stack (FIFO dan LIFO dalam satu struktur)
- Elemen bisa dimasukkan dari kedua sisi (depan atau belakang)
- Elemen bisa dikeluarkan dari kedua sisi (depan atau belakang)
- **Struktur:** Lebih kompleks, memerlukan pointer ekstra

### 4. **Priority Queue**
- Setiap elemen memiliki prioritas yang ditentukan saat enqueue
- Elemen dengan prioritas lebih tinggi akan keluar terlebih dahulu
- **Implementasi:** Array, linked list, binary heap, balanced tree
- **Jenis prioritas:**
  - **Descending:** Elemen prioritas lebih rendah keluar duluan (misal: penjadwalan CPU)
  - **Ascending:** Elemen prioritas lebih tinggi keluar duluan (misal: antrian pasien di rumah sakit berdasarkan urgensi)

---

## Implementasi

### **1. Menggunakan Array (Linear Queue)**

**Kelebihan:**
- Akses cepat dengan index (O(1))
- Sederhana untuk implementasi
- Memory terukur dengan ukuran fixed

**Kekurangan:**
- Ukuran fixed (tidak dinamis)
- Pemborosan memory pada queue linier
- Perlu shifting elemen saat dequeue

### **2. Menggunakan Linked List**

**Kelebihan:**
- Ukuran dinamis (dapat bertambah/berkurang sesuai kebutuhan)
- Tidak ada pemborosan memory
- Dequeue tidak perlu shifting elemen

**Kekurangan:**
- Memory tambahan untuk pointer di setiap node
- Akses elemen memerlukan traversal (lebih lambat)

---

## Implementasi di File Ini

File `queue.cpp` mengimplementasikan **Queue Linier menggunakan Array** dengan fitur:

### Class: `NilaiMatkul`
Struktur data untuk menyimpan informasi nilai mata kuliah:
- `nim`: Nomor Induk Mahasiswa
- `nama`: Nama mahasiswa
- `nilai`: Nilai mata kuliah

### Class: `Queue`
Implementasi queue dengan array statis (ukuran 10 elemen):

**Private Members:**
- `first`: Index elemen depan (front)
- `last`: Index elemen belakang (rear)
- `data[10]`: Array untuk menyimpan data

**Public Methods:**
- `Queue()`: Constructor, inisialisasi `first` dan `last` ke -1
- `isEmpty()`: Cek apakah queue kosong
- `isFull()`: Cek apakah queue penuh
- `add()`: Enqueue (menambah data baru)
- `del()`: Dequeue (menghapus data dari depan)
- `printQueue()`: Menampilkan isi queue

**Contoh Penggunaan:**
```cpp
Queue q;
q.add("123456781", "Nana", 64.75);
q.add("123456782", "Banu", 75.11);
q.add("123456783", "Dea", 84.43);
q.printQueue();
q.del();
```

---

## Istilah Penting

- **Overflow:** Kondisi queue penuh, tidak bisa menambah elemen lagi
- **Underflow:** Kondisi queue kosong, tidak bisa menghapus elemen
- **FIFO:** First In First Out (masuk duluan, keluar duluan)
- **LIFO:** Last In First Out (masuk terakhir, keluar duluan) - karakteristik stack 
