using entities.Concrete;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bll.Abstract
{
    public interface IEmanettekiKitaplarBll
    {
        List<emanettekiKitaplar> getAll();
        List<emanettekiKitaplar> getAllByBookId(int bookId);
        List<emanettekiKitaplar> getAllByStudentId(int studentId);
        emanettekiKitaplar getOneById(int id);
        void Update(emanettekiKitaplar emanettekiKitaplar);
        void Add(emanettekiKitaplar emanettekiKitaplar);
        void Delete(emanettekiKitaplar emanettekiKitaplar);
    }
}
