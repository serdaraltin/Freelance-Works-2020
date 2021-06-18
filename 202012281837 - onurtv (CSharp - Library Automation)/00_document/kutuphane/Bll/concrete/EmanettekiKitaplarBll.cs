using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Bll.Abstract;
using Dal.Abstract;
using entities.Concrete;

namespace Bll.concrete
{
    public class EmanettekiKitaplarBll : IEmanettekiKitaplarBll
    {
        IEmanettekiKitaplarDal _EmanettekiKitaplar;
        public EmanettekiKitaplarBll(IEmanettekiKitaplarDal EmanettekiKitaplar)
        {
            _EmanettekiKitaplar = EmanettekiKitaplar;
        }
        public void Add(emanettekiKitaplar emanettekiKitaplar)
        {
            _EmanettekiKitaplar.Add(emanettekiKitaplar);
        }

        public void Delete(emanettekiKitaplar emanettekiKitaplar)
        {
            _EmanettekiKitaplar.Delete(emanettekiKitaplar);
        }

        public List<emanettekiKitaplar> getAll()
        {
            return _EmanettekiKitaplar.getAll(x=>x.kitaplar.emanetDurumu==true);
        }

        public List<emanettekiKitaplar> getAllByBookId(int bookId)
        {
            return _EmanettekiKitaplar.getAll(x => x.kitapID == bookId);
        }

        public List<emanettekiKitaplar> getAllByStudentId(int studentId)
        {
            return _EmanettekiKitaplar.getAllByStudentId(studentId);
        }

        public emanettekiKitaplar getOneById(int id)
        {
            return _EmanettekiKitaplar.getOne(x => x.id == id);
        }

        public void Update(emanettekiKitaplar emanettekiKitaplar)
        {
            _EmanettekiKitaplar.Update(emanettekiKitaplar);
        }
    }
}
